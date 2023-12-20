import socket
from time import sleep

from server_socket.service.ServerSocketServiceImpl import ServerSocketServiceImpl
from utility.IPAddressBindSupporter import IPAddressBindSupporter

if __name__ == '__main__':
    print(f"ip: {IPAddressBindSupporter.getIpAddress()}")
    print(f"ip: {IPAddressBindSupporter.getLocalIPAddress()}")

    serverSocketService = ServerSocketServiceImpl()
    serverSocketService.createServerSocket(IPAddressBindSupporter.getLocalIPAddress(), 33333)
    serverSocketService.setSocketOption(socket.SOL_SOCKET, socket.SO_REUSEADDR)
    serverSocketService.bindServerSocket()
    serverSocketService.setServerListenNumber(1)
    serverSocketService.setBlockingOperation()

    while True:
        try:
            serverSocketService.acceptClientSocket()

        except socket.error:
            sleep(0.5)