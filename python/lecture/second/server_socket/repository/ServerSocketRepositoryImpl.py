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

    # 실제로는 SOL_SOCKET, SO_REUSEADDR이 들어오므로
    # IP 및 PORT를 지속적으로 재사용 함을 의미하나
    # 추후 확장에서 다른 옵션들도 활용 될 수 있으므로 아래와 같이 구성함
    def setSocketOption(self, apiControlLevel, OptionName):
        socketObject = self.__serverSocket.getSocket()
        socketObject.setsockopt(apiControlLevel, OptionName, 1)


