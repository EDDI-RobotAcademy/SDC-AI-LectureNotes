from server_socket.repository.ServerSocketRepositoryImpl import ServerSocketRepositoryImpl
from server_socket.service.ServerSocketService import ServerSocketService


class ServerSocketServiceImpl(ServerSocketService):
    def __init__(self):
        print("ServerSocketServiceImpl 생성자 호출")
        self.__serverSocketRepository = ServerSocketRepositoryImpl()
        # self.__clientSocketRepository = ClientSocketRepositoryImpl()

    def createServerSocket(self, host, port):
        return self.__serverSocketRepository.create(host, port)

