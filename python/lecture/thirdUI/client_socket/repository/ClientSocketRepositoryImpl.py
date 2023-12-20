import socket

from client_socket.entity.ClientSocket import ClientSocket
from client_socket.repository.ClientSocketRepository import ClientSocketRepository


class ClientSocketRepositoryImpl(ClientSocketRepository):
    __instance = None

    def __new__(cls):
        if cls.__instance is None:
            cls.__instance = super().__new__(cls)
        return cls.__instance

    def __init__(self):
        print("ClientSocketRepository 생성자 호출")
        self.__clientSocket = None

    def create(self, host, port):
        socketObject = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.__clientSocket = ClientSocket(host, port, socketObject)
        return self.__clientSocket

    def setBlockingOperation(self):
        socketObject = self.__clientSocket.getSocket()
        socketObject.setblocking(False)


