import ast
from base64 import b64encode

from console_ui.repository.ConsoleUiRepositoryImpl import ConsoleUiRepositoryImpl
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

            cls.__requestFormGenerationTable[
                CustomProtocol.PRODUCT_LIST.value] = cls.__instance.generateProductListRequest
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

    # 사실 이 부분은 python Dictionary를 사용하여 개선하는 것이 더 좋음
    def findRequestGenerator(self, protocolNumber):
        print("RequestGeneratorService: request generator를 찾아옵니다")
        if self.__requestFormGenerationTable[protocolNumber] is not None:
            return self.__requestFormGenerationTable[protocolNumber]

        else:
            print(f"이 프로토콜 번호({protocolNumber}) 를 처리 할 수 있는 함수가 없습니다.")

    def generateAccountRegisterRequest(self, arguments):
        print("RequestGeneratorService: register form")
        print(f"arguments의 타입: {type(arguments)}")
        print(f"지금부터 request를 생성합니다: {arguments}")

        if not isinstance(arguments, tuple) or len(arguments) != 2:
            raise ValueError("Invalid request format")

        print("make account request dictionary")

        accountRequestData = {
            '__accountId': arguments[0].decode().strip(),
            '__password': arguments[1].decode().strip(),
        }

        return accountRequestData

    def generateAccountLoginRequest(self, arguments):
        print("RequestGeneratorService: login form")

        if not isinstance(arguments, tuple) or len(arguments) != 2:
            raise ValueError("Invalid request format")

        accountRequestData = {
            '__accountId': arguments[0].decode().strip(),
            '__password': arguments[1].decode().strip(),
        }

        return accountRequestData

    def generateAccountLogoutRequest(self, arguments):
        print(f"RequestGeneratorService: logout form sessionId: {arguments}")

        accountRequestData = {
            '__accountSessionId': arguments,
        }

        return accountRequestData

    def generateAccountDeleteRequest(self, arguments):
        print("RequestGeneratorService: delete form")

        accountRequestData = {
            '__accountSessionId': arguments,
        }

        return accountRequestData

    def generateProductListRequest(self, arguments):
        print("RequestGeneratorService - generateProductListRequest()")
        return

    def generateProductRegisterRequest(self, arguments, sessionId):
        print(f"RequestGeneratorService - generateProductRegisterRequest() arguments: {arguments}")

        if not isinstance(arguments, tuple) or len(arguments) != 3:
            raise ValueError("Invalid request format")

        productRequestData = {
            '__name': arguments[0].decode().strip(),
            '__price': arguments[1],
            '__details': arguments[2].decode().strip(),
            '__sessionId': sessionId,
        }

        return productRequestData

    def generateProductReadRequest(self, arguments, sessionId):
        print(f"RequestGeneratorService - generateProductReadRequest() arguments: {arguments}")

        productRequestData = {
            '__id': arguments,
            '__sessionId': sessionId,
        }

        return productRequestData

    def generateProductUpdateRequest(self, arguments, sessionId, productReadNo):
        print(f"RequestGeneratorService - generateProductUpdateRequest() arguments: {arguments}")

        if not isinstance(arguments, tuple) or len(arguments) != 3:
            raise ValueError("Invalid request format")

        productRequestData = {
            '__name': arguments[0].decode().strip(),
            '__price': arguments[1],
            '__details': arguments[2].decode().strip(),
            '__sessionId': sessionId,
            '__id': productReadNo,
        }

        return productRequestData

    def generateProductDeleteRequest(self, sessionId, productReadNo):
        print(f"RequestGeneratorService - generateProductDeleteRequest()")

        productRequestData = {
            '__sessionId': sessionId,
            '__id': productReadNo,
        }

        return productRequestData

    def generateProductSearchRequest(self, userInputKeyword):
        print(f"RequestGeneratorService - generateProductDeleteRequest()")

        productRequestData = {
            '__userInputKeyword': userInputKeyword,
        }

        return b64encode(productRequestData['__userInputKeyword']).decode()

    def generateOrderListRequest(self, sessionId):
        print(f"RequestGeneratorService - generateOrderRegisterRequest()")

        productRequestData = {
            '__sessionId': sessionId
        }

        return productRequestData

    def generateOrderRegisterRequest(self, sessionId, productId):
        print(f"RequestGeneratorService - generateOrderRegisterRequest()")

        productRequestData = {
            '__sessionId': sessionId,
            '__productId': productId,
        }

        return productRequestData

    def generateProgramExitRequest(self, arguments):
        print("RequestGeneratorService - generateProgramExitRequest()")
        return


