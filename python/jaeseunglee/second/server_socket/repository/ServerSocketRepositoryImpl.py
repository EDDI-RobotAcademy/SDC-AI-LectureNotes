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
        socketObject.bind((
            self.__serverSocket.getHost(),
            self.__serverSocket.getPort()))

    def setListenNumber(self, howManyAccessHere):
        socketObject = self.__serverSocket.getSocket()
        socketObject.listen(howManyAccessHere)

    def setBlockingOperation(self):
        socketObject = self.__serverSocket.getSocket()
        socketObject.setblocking(False)

    def acceptClientSocket(self):
        try:
            serverSocketObject = self.__serverSocket.getSocket()
            clientSocket, clientAddress = serverSocketObject.accept()
            print(f"사용자가 접속했습니다: {clientAddress}")
            return clientSocket, clientAddress


        except BlockingIOError:
            print("현재 출입을 시도하는 사용자가 없습니다!")
            sleep(0.5)
            # 여태까지 다룬 언어들은 동시에 2개를 리턴할 수 없었음
            # 구조체나 객체화하여 리턴하는것이 일반적
            # 하지만 파이썬은 여러개 리턴 쌉가능
            return None, None

        except Exception as exception:
            print(f"사용자 승인 중 에러 발생:  {exception}")
            return None, None

