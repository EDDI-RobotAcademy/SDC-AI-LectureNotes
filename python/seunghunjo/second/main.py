import multiprocessing
import socket
from time import sleep
from decouple import config

from server_socket.repository.ServerSocketRepositoryImpl import ServerSocketRepositoryImpl
from server_socket.service.ServerSocketServiceImpl import ServerSocketServiceImpl
from task_manage.repository.TaskManageRepositoryImpl import TaskManageRepositoryImpl
from task_manage.service.TaskManageServiceImpl import TaskManageServiceImpl
from utility.IPAddressBindSupporter import IPAddressBindSupporter
from mysql.MySQLProcess import DbProcess
# pip3 install pymysql

MYHOST = IPAddressBindSupporter.getIpAddressFromGoogle()


def initMysqlInstance():
    dbInstance = DbProcess(
        host=config('HOST'),
        user=config('DB_USER'),
        password=config('PASSWORD'),
        database=config('DATABASE')
    )
    dbInstance.connect()


def initServerSocketDomain():
    serverSocketRepository = ServerSocketRepositoryImpl()
    ServerSocketServiceImpl(serverSocketRepository)


def initTaskManageDomain():
    taskManageRepository = TaskManageRepositoryImpl()
    TaskManageServiceImpl(taskManageRepository)


def initEachDomain():
    initMysqlInstance()

    initServerSocketDomain()
    initTaskManageDomain()


if __name__ == '__main__':
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

    taskManageService = TaskManageServiceImpl.getInstance()

    queue = multiprocessing.Queue()

    while True:
        try:
            serverSocketService.acceptClientSocket(queue)

            if not queue.empty():
                print("사용자가 접속했습니다!")
                taskManageService.createReceiveTask()
                taskManageService.createTransmitTask()

        except socket.error:
            sleep(1.0)


# 보편적으로 서비스를 제공하는 입장에 놓여 있으면 Server(서버)
# 서비스를 받는 입장에 있으면 Client(클라이언트) 라고 합니다.
# 앞으로 만들 UI는 현재 작성한 Server에게 요청(Request)를 합니다.
# 그럼 UI는 Server가 준 응답(Response)를 가지고 지 나름대로의 기준으로 처리를 합니다.