import socket
from time import sleep

from server_socket.entity.ClientSocket import ClientSocket
from server_socket.entity.ServerSocket import ServerSocket
from server_socket.repository.ServerSocketRepository import ServerSocketRepository


class ServerSocketRepositoryImpl(ServerSocketRepository):
    __instance = None
    __clientSocketList = []

    def __new__(cls):
        if cls.__instance is None:
            cls.__instance = super().__new__(cls)
        return cls.__instance

    def __init__(self):
        print("ServerSocketRepositoryImpl 생성자 호출")
        self.__serverSocket = None

    @classmethod
    def getInstance(cls):
        if cls.__instance is None:
            cls.__instance = cls()
        return cls.__instance

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

    # bind 작업을 통해 실제 Server Socket이 IP와 Port를 관리하게됨
    # 실제 Network 를 활용 할 수 있는 객체가 되는 시점
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

            if clientSocket:
                print(f"사용자가 접속했습니다: {clientAddress}")

                self.__clientSocketList.append(ClientSocket(clientSocket, clientAddress))

                return clientSocket, clientAddress

        except BlockingIOError:
            # print("현재 출입을 시도하는 사용자가 없습니다!")
            sleep(0.5)
            # 여태까지 다룬 언어들은 동시에 2개를 리턴하지 못하기 때문에
            # 구조체나 객체화하여 리턴해야했음
            # python은 아래와 같이 그냥 리턴하고 싶은 개수로 던져버리면
            # 알아서 tuple 이라는 형식으로 묶어(구조체 비슷하다 생각하면 됨)서 리턴함
            return None, None

        except Exception as exception:
            print(f"사용자 승인 중 에러 발생: {exception}")
            return None, None

    def getServerSocket(self):
        return self.__serverSocket

    def getClientSocketList(self):
        return self.__clientSocketList
