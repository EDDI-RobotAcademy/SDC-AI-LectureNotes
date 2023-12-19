import socket
from time import sleep

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
    def setSocketOption(self, apiControlLevel, optionName):
        socketObject = self.__serverSocket.getSocket()
        socketObject.setsockopt(apiControlLevel, optionName, 1)

    def bindServerSocket(self):
        socketObject = self.__serverSocket.getSocket()
        socketObject.bind((self.__serverSocket.getHost(), self.__serverSocket.getPort()))

    def setServerListenNumber(self, howManyConnections):
        socketObject = self.__serverSocket.getSocket()
        socketObject.listen(howManyConnections)

    def setBlockingOperation(self):
        socketObject = self.__serverSocket.getSocket()
        socketObject.setblocking(False)

    def acceptClientSocket(self):
        try:
            serverSocketObject = self.__serverSocket.getSocket()
            clientSocket, clientAddress = serverSocketObject.accept()
            print(f'User Connected to {clientAddress}')
            return clientSocket, clientAddress
        except BlockingIOError:
            print('No Connection')
            sleep(0.5)
            # 여태까지 다룬 언어들은 동시에 2개를 리턴하지 못하기 때문에
            # 구조체나 객체화하여 리턴해야했음
            # python은 아래와 같이 그냥 리턴하고 싶은 개수로 던져버리면
            # 알아서 tuple 이라는 형식으로 묶어(구조체 비슷하다 생각하면 됨)서 리턴함
            return None, None

        except Exception as exception:
            print(f'Exception: {exception}')
            return None, None