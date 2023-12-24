from console_printer.repository.ConsolePrinterRepositoryImpl import ConsolePrinterRepositoryImpl
from task_manage.service.TaskManageService import TaskManageService
from receiver.repository.ReceiverRepositoryImpl import ReceiverRepositoryImpl
from task_manage.repository.TaskManageRepositoryImpl import TaskManageRepositoryImpl
from transmitter.repository.TransmitterRepositoryImpl import TransmitterRepositoryImpl
from client_socket.repository.ClientSocketRepositoryImpl import ClientSocketRepositoryImpl


class TaskManageServiceImpl(TaskManageService):
    __instance = None

    def __new__(cls, repository):
        if cls.__instance is None:
            cls.__instance = super().__new__(cls)
            cls.__instance.repository = repository
        return cls.__instance

    def __init__(self, repository):
        print("TaskManageServiceImpl 생성자 호출")
        self.__taskManageRepository = TaskManageRepositoryImpl()

    # python 은 repository=None 으로 파라미터 없으면 그냥 처리함
    @classmethod
    def getInstance(cls, repository=None):
        if cls.__instance is None:
            cls.__instance = cls(repository)
        return cls.__instance

    # 결국 TransmitTask 를 만들기 위해서는 transmitQueue 가 필요함
    def createTransmitTask(self, lock, transmitQueue):
        transmitterRepository = TransmitterRepositoryImpl.getInstance()
        clientSocketRepository = ClientSocketRepositoryImpl.getInstance()

        # transmitter 에 있는 transmitCommand 를 하는 Task(ps -ef) 생성
        # 신입 사원 뽑았다 생각하면 됨
        self.__taskManageRepository.createTask(
            target=transmitterRepository.transmitCommand,
            args=(clientSocketRepository.getClientSocket(), lock, transmitQueue)
        )

    def createReceiveTask(self, lock):
        receiverRepository = ReceiverRepositoryImpl.getInstance()
        clientSocketRepository = ClientSocketRepositoryImpl.getInstance()

        # 현재 Receiver 와 Transmitter 가 Socket 자원을 공유하고 있는 문제가 있음
        # 그래서 Transmitter 가 쏘는 중에 Receiver 가 Socket 을 사용하려 하면 충돌이 발생함
        # 그러므로 Receiver 가 사용 할 때, Transmitter 가 사용 할 때
        # 각각에 대해 명확한 기준을 가질 수 있도록 Lock을 걸어줘야함

        # receiver 에 있는 receiveCommand 를 하는 Task(ps -ef) 생성
        # 신입 사원 뽑았다 생각하면 됨
        self.__taskManageRepository.createTask(
            target=receiverRepository.receiveCommand,
            args=(clientSocketRepository.getClientSocket(), lock)
        )

    # 원래는 server 가 보내는 정보를 receiver 에서 받아서 receiverQueue 로 받아야 하는 것 아닌가 ?
    def createPrinterTask(self, transmitQueue):
        consolePrinterRepository = ConsolePrinterRepositoryImpl.getInstance()

        self.__taskManageRepository.createTask(
            target=consolePrinterRepository.printConsoleUi,
            args=(transmitQueue, )
        )