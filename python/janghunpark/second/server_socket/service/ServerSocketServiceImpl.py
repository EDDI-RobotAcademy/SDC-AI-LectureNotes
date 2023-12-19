from server_socket.service.ServerSocketService import ServerSocketService
from server_socket.repository.ServerSocketRepositoryImpl import ServerSocketRepositoryImpl


class ServerSocketServiceImpl(ServerSocketService):
    def __init__(self):
        print("ServerSocketServiceImpl : Initiator Call")
        self.__serverSocketRepository = ServerSocketRepositoryImpl()
        # self.__clientSocketRepository = ClientSocketRepositoryImpl()

    def createServerSocket(self, host, port):
        pass
        return self.__serverSocketRepository.create(host, port)

    def setSocketRepository(self, apiControlLevel, optionName):
        pass