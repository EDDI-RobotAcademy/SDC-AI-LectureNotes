import ast
from base64 import b64decode

from account.service.request.AccountDeleteRequest import AccountDeleteRequest
from account.service.request.AccountLoginRequest import AccountLoginRequest
from account.service.request.AccountLogoutRequest import AccountLogoutRequest
from account.service.request.AccountRegisterRequest import AccountRegisterRequest

from custom_protocol.entity.CustomProtocol import CustomProtocol
from order.service.request.OrderListRequest import OrderListRequest
from order.service.request.OrderRegisterRequest import OrderRegisterRequest
from product.service.request.ProductDeleteRequest import ProductDeleteRequest
from product.service.request.ProductReadRequest import ProductReadRequest
from product.service.request.ProductRegisterRequest import ProductRegisterRequest
from product.service.request.ProductSearchRequest import ProductSearchRequest
from product.service.request.ProductUpdateRequest import ProductUpdateRequest
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

            cls.__requestFormGenerationTable[
                CustomProtocol.PRODUCT_REGISTER.value] = cls.__instance.generateProductRegisterRequest
            cls.__requestFormGenerationTable[
                CustomProtocol.PRODUCT_READ.value] = cls.__instance.generateProductReadRequest
            cls.__requestFormGenerationTable[
                CustomProtocol.PRODUCT_UPDATE.value] = cls.__instance.generateProductUpdateRequest
            cls.__requestFormGenerationTable[
                CustomProtocol.PRODUCT_DELETE.value] = cls.__instance.generateProductDeleteRequest
            cls.__requestFormGenerationTable[
                CustomProtocol.PRODUCT_SEARCH.value] = cls.__instance.generateProductSearchRequest

            cls.__requestFormGenerationTable[
                CustomProtocol.ORDER_LIST.value] = cls.__instance.generateOrderListRequest
            cls.__requestFormGenerationTable[
                CustomProtocol.ORDER_REGISTER.value] = cls.__instance.generateOrderRegisterRequest


            cls.__requestFormGenerationTable[
                CustomProtocol.PROGRAM_EXIT.value] = cls.__instance.generateProgramExitRequest


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

    def generateProductRegisterRequest(self, arguments):
        return ProductRegisterRequest(
            __name=arguments["__name"],
            __price=arguments["__price"],
            __details=arguments["__details"],
            __sessionId=arguments["__sessionId"]
        )

    def generateProductReadRequest(self, arguments):
        return ProductReadRequest(
            __id=arguments["__id"],
            __sessionId=arguments["__sessionId"]
        )

    def generateProductUpdateRequest(self, arguments):
        return ProductUpdateRequest(
            __id=arguments["__id"],
            __name=arguments["__name"],
            __price=arguments["__price"],
            __details=arguments["__details"],
            __sessionId=arguments["__sessionId"]
        )

    def generateProductDeleteRequest(self, arguments):
        return ProductDeleteRequest(
            __id=arguments["__id"],
            __sessionId=arguments["__sessionId"]
        )

    def generateProductSearchRequest(self, arguments):
        decodedBytes = b64decode(arguments)
        decodedString = decodedBytes.decode('utf-8')

        print("\033[91mArguments:", arguments,", decodeBytes:", decodedBytes,", decodedString:", decodedString)
        print("\033[92m", end="")

        return ProductSearchRequest(
            __userInputKeyword=decodedString.strip()
        )

    def generateOrderListRequest(self, arguments):
        return OrderListRequest(
            __sessionId=arguments["__sessionId"]
        )

    def generateOrderRegisterRequest(self, arguments):
        return OrderRegisterRequest(
            __productId=arguments["__productId"],
            __sessionId=arguments["__sessionId"]
        )

    def generateProgramExitRequest(self, arguments):
        print("\033[91m접속한 사용자가 프로그램을 종료했습니다!\033[92m")
        return None


