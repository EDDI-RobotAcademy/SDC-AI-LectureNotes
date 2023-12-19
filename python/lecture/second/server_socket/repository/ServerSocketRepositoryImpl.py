import socket

from server_socket.entity.ServerSocket import ServerSocket
from server_socket.repository.ServerSocketRepository import ServerSocketRepository


class ServerSocketRepositoryImpl(ServerSocketRepository):
    def __init__(self):
        self.__serverSocket = None

    def create(self, host, port):
        socketObject = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.__serverSocket = ServerSocket(host, port, socketObject)
        return self.__serverSocket


