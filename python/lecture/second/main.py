import socket
from time import sleep
from decouple import config

from server_socket.repository.ServerSocketRepositoryImpl import ServerSocketRepositoryImpl
from server_socket.service.ServerSocketServiceImpl import ServerSocketServiceImpl
from utility.IPAddressBindSupporter import IPAddressBindSupporter
from mysql.MySQLProcess import DbProcess

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


def initEachDomain():
    initMysqlInstance()

    initServerSocketDomain()


if __name__ == '__main__':
    print(f"ip: {IPAddressBindSupporter.getIpAddress()}")
    print(f"ip: {IPAddressBindSupporter.getLocalIPAddress()}")
    print(f"ip: {IPAddressBindSupporter.getIpAddressFromGoogle()}")

    initEachDomain()

    serverSocketService = ServerSocketServiceImpl.getInstance()

    serverSocketService.createServerSocket(MYHOST, int(config('PORT')))
    serverSocketService.setSocketOption(socket.SOL_SOCKET, socket.SO_REUSEADDR)
    serverSocketService.bindServerSocket()
    serverSocketService.setServerListenNumber(1)
    serverSocketService.setBlockingOperation()

    while True:
        try:
            serverSocketService.acceptClientSocket()

        except socket.error:
            sleep(0.5)
