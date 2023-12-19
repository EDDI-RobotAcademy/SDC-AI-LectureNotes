from server_socket.repository.ServerSocketRepositoryImpl import ServerSocketRepositoryImpl
from server_socket.service.ServerSocketService import ServerSocketService


class ServerSocketServiceImpl(ServerSocketService):
    def __init__(self):
        print("ServerSocketServiceImpl 생성자 호출")
        self.__serverSocketRepository = ServerSocketRepositoryImpl()
        # self.__clientSocketRepository = ClientSocketRepositoryImpl()

    def createServerSocket(self, host, port):
        return self.__serverSocketRepository.create(host, port)

    def setSocketOption(self, apiControlLevel, OptionName):
        self.__serverSocketRepository.setSocketOption(apiControlLevel, OptionName)

    def bindServerSocket(self):
        self.__serverSocketRepository.bindServerSocket()

    def setServerListenNumber(self, howManyAccessHere):
        self.__serverSocketRepository.setListenNumber(howManyAccessHere)

    def setBlockingOperation(self):
        self.__serverSocketRepository.setBlockingOperation()

    def acceptClientSocket(self):
        clientSocket, clientAddress = self.__serverSocketRepository.acceptClientSocket()




