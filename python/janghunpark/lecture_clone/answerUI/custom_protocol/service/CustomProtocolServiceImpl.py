from custom_protocol.repository.CustomProtocolRepositoryImpl import CustomProtocolRepositoryImpl
from custom_protocol.service.CustomProtocolService import CustomProtocolService


class CustomProtocolServiceImpl(CustomProtocolService):
    __instance = None

    def __new__(cls, repository):
        print("CustomProtocolServiceImpl 내가 찐 생성자")
        if cls.__instance is None:
            cls.__instance = super().__new__(cls)
            cls.__instance.repository = repository
        return cls.__instance

    def __init__(self, repository):
        print("CustomProtocolServiceImpl 초기화 작업")
        self.__customProtocolRepository = CustomProtocolRepositoryImpl()

    @classmethod
    def getInstance(cls, repository=None):
        if cls.__instance is None:
            cls.__instance = cls(repository)
        return cls.__instance

    def registerCustomProtocol(self, protocolNumber, pointerOfFunction):
        self.__customProtocolRepository.register(protocolNumber, pointerOfFunction)


