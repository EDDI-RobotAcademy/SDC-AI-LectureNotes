import atexit
import multiprocessing
import socket
from dataclasses import dataclass
from time import sleep

import sqlalchemy

from account.repository.AccountRepositoryImpl import AccountRepositoryImpl
from account.repository.SessionRepositoryImpl import SessionRepositoryImpl
from account.service.AccountServiceImpl import AccountServiceImpl

from custom_protocol.entity.CustomProtocol import CustomProtocol
from custom_protocol.service.CustomProtocolServiceImpl import CustomProtocolServiceImpl

from mysql.MySQLDatabase import MySQLDatabase

from order.repository.OrderRepositoryImpl import OrderRepositoryImpl
from order.service.OrderServiceImpl import OrderServiceImpl

from product.repository.ProductRepositoryImpl import ProductRepositoryImpl
from product.service.ProductServiceImpl import ProductServiceImpl

from server_socket.repository.ServerSocketRepositoryImpl import ServerSocketRepositoryImpl
from server_socket.service.ServerSocketServiceImpl import ServerSocketServiceImpl

from task_manage.repository.TaskManageRepositoryImpl import TaskManageRepositoryImpl
from task_manage.service.TaskManageServiceImpl import TaskManageServiceImpl
from utility.IPAddressBindSupporter import IPAddressBindSupporter
from mysql.MySQLProcess import DbProcess
# pip3 install pymysql

from sqlalchemy import create_engine
# pip3 install sqlalchemy
# pip3 install mysql-connector-python
from decouple import config

# from account.entity.Account import Account
# from product.entity.Product import Product

MYHOST = IPAddressBindSupporter.getIpAddressFromGoogle()


def initMysqlInstance():
    dbInstance = DbProcess(
        host=config('HOST'),
        user=config('DB_USER'),
        password=config('PASSWORD'),
        database=config('DATABASE')
    )
    dbInstance.connect()


def initMysqlInstanceAlternatives():
    mysqlDatabase = MySQLDatabase.getInstance()
    mysqlDatabase.connect()


def initServerSocketDomain():
    serverSocketRepository = ServerSocketRepositoryImpl()
    ServerSocketServiceImpl(serverSocketRepository)


def initTaskManageDomain():
    taskManageRepository = TaskManageRepositoryImpl()
    TaskManageServiceImpl(taskManageRepository)


@dataclass
class ProgramExitResponse:
    __isSuccess: bool


def clientExitProgram():
    print("\033[91m접속한 사용자가 프로그램을 종료했습니다\033[92m")

    return ProgramExitResponse(True)


def initCustomProtocol():
    customProtocolService = CustomProtocolServiceImpl.getInstance()
    accountService = AccountServiceImpl.getInstance()
    productService = ProductServiceImpl.getInstance()
    orderService = OrderServiceImpl.getInstance()

    print(f"enum value test: {CustomProtocol.ACCOUNT_REGISTER.value}")
    customProtocolService.registerCustomProtocol(
        CustomProtocol.ACCOUNT_REGISTER.value,
        accountService.registerAccount
    )

    customProtocolService.registerCustomProtocol(
        CustomProtocol.ACCOUNT_LOGIN.value,
        accountService.loginAccount
    )

    customProtocolService.registerCustomProtocol(
        CustomProtocol.ACCOUNT_LOGOUT.value,
        accountService.logoutAccount
    )

    customProtocolService.registerCustomProtocol(
        CustomProtocol.ACCOUNT_DELETE.value,
        accountService.deleteAccount
    )

    customProtocolService.registerCustomProtocol(
        CustomProtocol.PRODUCT_LIST.value,
        productService.listProduct
    )

    customProtocolService.registerCustomProtocol(
        CustomProtocol.PRODUCT_REGISTER.value,
        productService.registerProduct
    )

    customProtocolService.registerCustomProtocol(
        CustomProtocol.PRODUCT_READ.value,
        productService.readProduct
    )

    customProtocolService.registerCustomProtocol(
        CustomProtocol.PRODUCT_UPDATE.value,
        productService.updateProduct
    )

    customProtocolService.registerCustomProtocol(
        CustomProtocol.PRODUCT_DELETE.value,
        productService.deleteProduct
    )

    customProtocolService.registerCustomProtocol(
        CustomProtocol.PRODUCT_SEARCH.value,
        productService.searchProduct
    )

    customProtocolService.registerCustomProtocol(
        CustomProtocol.ORDER_LIST.value,
        orderService.orderList
    )

    customProtocolService.registerCustomProtocol(
        CustomProtocol.ORDER_REGISTER.value,
        orderService.orderRegister
    )

    customProtocolService.registerCustomProtocol(
        CustomProtocol.PROGRAM_EXIT.value,
        clientExitProgram
    )


def initAccountDomain():
    accountRepository = AccountRepositoryImpl()
    sessionRepository = SessionRepositoryImpl()

    AccountServiceImpl(accountRepository, sessionRepository)


def initProductDomain():
    accountRepository = AccountRepositoryImpl.getInstance()
    sessionRepository = SessionRepositoryImpl.getInstance()
    productRepository = ProductRepositoryImpl()
    ProductServiceImpl(accountRepository, sessionRepository, productRepository)


def initOrderDomain():
    accountRepository = AccountRepositoryImpl.getInstance()
    sessionRepository = SessionRepositoryImpl.getInstance()
    productRepository = ProductRepositoryImpl.getInstance()
    orderRepository = OrderRepositoryImpl.getInstance()
    OrderServiceImpl(accountRepository, sessionRepository, productRepository, orderRepository)


def initEachDomain():
    # initMysqlInstance()
    initMysqlInstanceAlternatives()

    initAccountDomain()
    initProductDomain()
    initOrderDomain()

    initServerSocketDomain()
    initTaskManageDomain()
    initCustomProtocol()




if __name__ == '__main__':
    print("\033[92m데이터 처리 서버가 구동되었습니다.")

    print(f"ip: {IPAddressBindSupporter.getIpAddress()}")
    print(f"ip: {IPAddressBindSupporter.getLocalIPAddress()}")
    print(f"ip: {IPAddressBindSupporter.getIpAddressFromGoogle()}")

    initEachDomain()

    serverSocketService = ServerSocketServiceImpl.getInstance()

    serverSocketService.createServerSocket(MYHOST, int(config('PORT')))
    serverSocketService.setSocketOption(socket.SOL_SOCKET, socket.SO_REUSEADDR)
    serverSocketService.bindServerSocket()
    serverSocketService.setServerListenNumber(15)
    serverSocketService.setBlockingOperation()

    # taskManageService = TaskManageServiceImpl.getInstance()

    queue = multiprocessing.Queue()

    while True:
        try:
            serverSocketService.acceptClientSocket(queue)

        except socket.error:
            sleep(1.0)


# 보편적으로 서비스를 제공하는 입장에 놓여 있으면 Server(서버)
# 서비스를 받는 입장에 있으면 Client(클라이언트) 라고 합니다.
# 앞으로 만들 UI는 현재 작성한 Server에게 요청(Request)를 합니다.
# 그럼 UI는 Server가 준 응답(Response)를 가지고 지 나름대로의 기준으로 처리를 합니다.
