from client_socket.repository.ClientSocketRepositoryImpl import ClientSocketRepositoryImpl
from console_printer.repository.ConsolePrinterRepositoryImpl import ConsolePrinterRepositoryImpl
from receiver.repository.ReceiverRepositoryImpl import ReceiverRepositoryImpl
from task_manage.repository.TaskManageRepositoryImpl import TaskManageRepositoryImpl
from task_manage.service.TaskManageService import TaskManageService
from transmitter.repository.TransmitterRepository import TransmitterRepository
from transmitter.repository.TransmitterRepositoryImpl import TransmitterRepositoryImpl


class TaskManageServiceImpl(TaskManageService):
    __instance = None
    # __lock = multiprocessing.Lock()

    def __new__(cls, repository):
        if cls.__instance is None:
            cls.__instance = super().__new__(cls)
            cls.__instance.repository = repository
        return cls.__instance

    def __init__(self, repository):
        print("TaskManageServiceImpl 생성자 호출")
        self.__taskManageRepository = TaskManageRepositoryImpl()

    # 파이썬은 repository=None 으로 파라미터 없으면 그냥 처리합니다
    @classmethod
    def getInstance(cls, repository=None):
        if cls.__instance is None:
            cls.__instance = cls(repository)
        return cls.__instance

    def createTransmitTask(self, lock, transmitQueue):
        transmitterRepository = TransmitterRepositoryImpl.getInstance()
        clientSocketRepository = ClientSocketRepositoryImpl.getInstance()

        # transmitter 있는 transmitCommand를 하는 Task(ps -ef) 생성
        # 신입 사원 뽑았다 생각하면 됨
        self.__taskManageRepository.createTask(
            target=transmitterRepository.transmitCommand,
            args=(clientSocketRepository.getClientSocket(), lock, transmitQueue)
        )

    def createReceiveTask(self, lock, receiveQueue, finishQueue):
        receiverRepository = ReceiverRepositoryImpl.getInstance()
        clientSocketRepository = ClientSocketRepositoryImpl.getInstance()

        self.__taskManageRepository.createTask(
            target=receiverRepository.receiveCommand,
            args=(clientSocketRepository.getClientSocket(), lock, receiveQueue, finishQueue)
        )

    def createPrinterTask(self, transmitQueue, receiveQueue):
        consolePrinterRepository = ConsolePrinterRepositoryImpl.getInstance()

        self.__taskManageRepository.createTask(
            target=consolePrinterRepository.printConsoleUi,
            args=(transmitQueue, receiveQueue, )
        )

    def closeEveryTask(self):
        print("모든 태스크를 종료합니다")
        # taskList = self.__taskManageRepository.getTaskEntityList()
        # for task in taskList:
        #     print(f"task.getTaskPid(): {task.getTaskPid()}")

