from client_socket.repository.ClientSocketRepositoryImpl import ClientSocketRepositoryImpl
from task_manage.repository.TaskManageRepositoryImpl import TaskManageRepositoryImpl
from task_manage.service.TaskManageService import TaskManageService
from transmitter.repository.TransmitterRepository import TransmitterRepository
from transmitter.repository.TransmitterRepositoryImpl import TransmitterRepositoryImpl


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

    # 파이썬은 repository=None 으로 파라미터 없으면 그냥 처리합니다
    @classmethod
    def getInstance(cls, repository=None):
        if cls.__instance is None:
            cls.__instance = cls(repository)
        return cls.__instance

    def createTransmitTask(self):
        transmitterRepository = TransmitterRepositoryImpl.getInstance()
        clientSocketRepository = ClientSocketRepositoryImpl.getInstance()

        self.__taskManageRepository.createTask(
            target=transmitterRepository.transmitCommand,
            args=(clientSocketRepository.getClientSocket(), )
        )
