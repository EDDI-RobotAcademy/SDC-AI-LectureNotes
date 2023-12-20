from client_socket.repository.ClientSocketRepositoryImpl import ClientSocketRepositoryImpl
from client_socket.service.ClientSocketService import ClientSocketService


class ClientSocketServiceImpl(ClientSocketService):
    __instance = None

    def __new__(cls, repository):
        if cls.__instance is None:
            cls.__instance = super().__new__(cls)
            cls.__instance.repository = repository
        return cls.__instance

    def __init__(self, repository):
        print("ClientSocketRepositoryImpl 생성자 호출")
        self.__clientSocketRepository = ClientSocketRepositoryImpl()
        # self.__clientSocketRepository = ClientSocketRepositoryImpl()

    @classmethod
    def getInstance(cls, repository=None):
        if cls.__instance is None:
            cls.__instance = cls(repository)
        return cls.__instance

    def createClientSocket(self, host, port):
        return self.__clientSocketRepository.create(host, port)

    def connectToTargetHost(self):
        return self.__clientSocketRepository.connectionToTargetHost()

    def setBlockingOperation(self):
        self.__clientSocketRepository.setBlockingOperation()




