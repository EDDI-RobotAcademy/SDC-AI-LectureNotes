from client_socket.repository.ClientSocketRepositoryImpl import ClientSocketRepositoryImpl
from task_manage.repository.ReceiverRepositoryImpl import ReceiverRepositoryImpl
from task_manage.repository.TaskManageRepositoryImpl import TaskManageRepositoryImpl
from task_manage.service.TaskManageService import TaskManageService
from task_manage.repository.TransmitterRepositoryImpl import TransmitterRepositoryImpl


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

    def createTransmitTask(self, lock):
        transmitterRepository = TransmitterRepositoryImpl.getInstance()
        clientSocketRepository = ClientSocketRepositoryImpl.getInstance()

        # transmitter 있는 transmitCommand를 하는 Task(ps -ef) 생성
        # 신입 사원 뽑았다 생각하면 됨
        self.__taskManageRepository.createTask(
            target=transmitterRepository.transmitCommand,
            args=(clientSocketRepository.getClientSocket(), lock)
        )

    def createReceiveTask(self, lock):
        receiverRepository = ReceiverRepositoryImpl.getInstance()
        clientSocketRepository = ClientSocketRepositoryImpl.getInstance()

        # 현재 Receiver와 Transmitter가 Socket 자원을 공유하고 있는 문제가 있음
        # 그래서 Transmitter가 쏘는 중에 Receiver가 Socket을 사용하려고하면 충돌이 발생함
        # 그러므로 Receiver가 사용 할 때, Transmitter가 사용 할 때
        # 각각에 대해 명확한 기준을 가질 수 있도록 Lock을 걸어줘야함

        # receiver에 있는 receiveCommand를 하는 Task(ps -ef) 생성
        # 신입 사원 뽑았다 생각하면 됨
        self.__taskManageRepository.createTask(
            target=receiverRepository.receiveCommand,
            args=(clientSocketRepository.getClientSocket(), lock)
        )
