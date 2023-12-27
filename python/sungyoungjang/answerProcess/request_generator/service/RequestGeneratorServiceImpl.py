import ast

from account.service.request.AccountDeleteRequest import AccountDeleteRequest
from account.service.request.AccountLoginRequest import AccountLoginRequest
from account.service.request.AccountLogoutRequest import AccountLogoutRequest
from account.service.request.AccountRegisterRequest import AccountRegisterRequest
from custom_protocol.entity.CustomProtocol import CustomProtocol
from request_generator.service.RequestGeneratorService import RequestGeneratorService


class RequestGeneratorServiceImpl(RequestGeneratorService):
    __instance = None
    __requestFormGenerationTable = {}

    def __new__(cls):
        if cls.__instance is None:
            cls.__instance = super().__new__(cls)

            cls.__requestFormGenerationTable[
                CustomProtocol.ACCOUNT_REGISTER.value] = cls.__instance.generateAccountRegisterRequest
            cls.__requestFormGenerationTable[
                CustomProtocol.ACCOUNT_LOGIN.value] = cls.__instance.generateAccountLoginRequest
            cls.__requestFormGenerationTable[
                CustomProtocol.ACCOUNT_LOGOUT.value] = cls.__instance.generateAccountLogoutRequest
            cls.__requestFormGenerationTable[
                CustomProtocol.ACCOUNT_DELETE.value] = cls.__instance.generateAccountDeleteRequest

        return cls.__instance

    def __init__(self):
        print("RequestGeneratorServiceImpl 생성자 호출")

    @classmethod
    def getInstance(cls):
        if cls.__instance is None:
            cls.__instance = cls()
        return cls.__instance

    def findRequestGenerator(self, protocolNumber):
        print("RequestGeneratorService - request generator를 찾아옵니다")
        if self.__requestFormGenerationTable[protocolNumber] is not None:
            return self.__requestFormGenerationTable[protocolNumber]

        else:
            print(f"이 프로토콜 번호({protocolNumber}) 를 처리 할 수 있는 함수가 없습니다.")

    def generateAccountRegisterRequest(self, arguments):
        print("RequestGeneratorService - AccountRegisterRequest 생성")
        return AccountRegisterRequest(
            __accountId=arguments["__accountId"],
            __password=arguments["__password"]
        )

    def generateAccountLoginRequest(self, arguments):
        print("RequestGeneratorService - AccountLoginRequest 생성")
        return AccountLoginRequest(
            __accountId=arguments["__accountId"],
            __password=arguments["__password"]
        )

    def generateAccountLogoutRequest(self, arguments):
        return AccountLogoutRequest(
            __accountSessionId=arguments["__accountSessionId"]
        )

    def generateAccountDeleteRequest(self, arguments):
        return AccountDeleteRequest(
            __accountSessionId=arguments["__accountSessionId"]
        )

