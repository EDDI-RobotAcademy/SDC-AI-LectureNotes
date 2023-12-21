from receiver.repository.ReceiverRepositoryImpl import ReceiverRepositoryImpl
from server_socket.repository.ServerSocketRepositoryImpl import ServerSocketRepositoryImpl
from server_socket.service.ServerSocketService import ServerSocketService
from task_manage.repository.TaskManageRepositoryImpl import TaskManageRepositoryImpl
from transmitter.repository.TransmitterRepositoryImpl import TransmitterRepositoryImpl


class ServerSocketServiceImpl(ServerSocketService):
    def __init__(self):
        print("ServerSocketServiceImpl : Initiator Call")
        self.__serverSocketRepository = ServerSocketRepositoryImpl()
        # self.__clientSocketRepository = ClientSocketRepositoryImpl()

    def createServerSocket(self, host, port):
        return self.__serverSocketRepository.create(host, port)

    def setSocketOption(self, apiControlLevel, optionName):
        self.__serverSocketRepository.setSocketOption(apiControlLevel, optionName)

    def bindServerSocket(self):
        self.__serverSocketRepository.bindServerSocket()

    def setServerListenNumber(self, howManyConnections):
        self.__serverSocketRepository.setServerListenNumber(howManyConnections)

    def setBlockingOperation(self):
        self.__serverSocketRepository.setBlockingOperation()

    # 데이터 구조체 (queue)
    # queue 에 socket 과 address 를 넣어서 보관
    def acceptClientSocket(self, queue):
        clientSocket, clientAddress = self.__serverSocketRepository.acceptClientSocket()

        if clientSocket is not None:
            taskManageRepository = TaskManageRepositoryImpl.getInstance()
            transmitterRepository = TransmitterRepositoryImpl.getInstance()
            receiverRepository = ReceiverRepositoryImpl.getInstance()

            taskManageRepository.createTask(
                target=transmitterRepository.transmitCommand,
                args=(clientSocket,)
            )

            taskManageRepository.createTask(
                target=receiverRepository.receiveCommand,
                args=(clientSocket,)
            )

            print("clientSocket: {}, clientAddress: {}".format(clientSocket, clientAddress))
            queue.put((clientSocket, clientAddress))
