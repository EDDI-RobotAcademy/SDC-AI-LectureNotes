from custom_protocol.repository.CustomProtocolRepository import CustomProtocolRepository


class CustomProtocolRepositoryImpl(CustomProtocolRepository):
    __instance = None

    __customProtocolTable = []

    def __new__(cls):
        if cls.__instance is None:
            cls.__instance = super().__new__(cls)
            cls.__customProtocolTable.append(cls.notImplemented)
        return cls.__instance

    def __init__(self):
        print("ClientSocketRepository 생성자 호출")
        self.__clientSocket = None

    @classmethod
    def getInstance(cls):
        if cls.__instance is None:
            cls.__instance = cls()
        return cls.__instance

    def notImplemented(self):
        print("아직 구현되지 않은 기능입니다")

    # 참고로 python은 '__' 가 붙으면 무조건 private 입니다.
    def __importCustomProtocol(self, protocolNumber, pointerOfFunction):
        print("python 스타일에 맞게 타입 추론이 필요함")

        if callable(pointerOfFunction):
            customProtocolTableLength = len(self.__customProtocolTable)

            if customProtocolTableLength > protocolNumber + 1:
                # 배열에 집어넣는 방법 (append)
                # self.__customProtocolTable.append(pointerOfFunction)
                self.__customProtocolTable[protocolNumber] = pointerOfFunction

            else:
                self.__customProtocolTable = [0] * (protocolNumber + 1)
                self.__customProtocolTable[protocolNumber] = pointerOfFunction
        else:
            print("실행 할 수 없는 형태입니다.")

    def register(self, protocolNumber, pointerOfFunction):
        print(f"{protocolNumber} 번호에 대응할 Handler: {pointerOfFunction}")

        self.__importCustomProtocol(protocolNumber, pointerOfFunction)

    def __protocolTableExecution(self, protocolNumber, *arguments, **mapArguments):
        if self.__customProtocolTable[protocolNumber] is not self.notImplemented:
            pointerOfFunction = self.__customProtocolTable[protocolNumber]
            result = pointerOfFunction(*arguments, **mapArguments)
            return result

        print(f"{protocolNumber} 프로토콜은 등록된 적이 없습니다.")

    def execute(self, protocolNumber, *arguments, **mapArguments):
        print(f"{protocolNumber} 를 실행합니다!")

        for key, value in mapArguments.items():
            print(f"{key}: {value}")

        self.__protocolTableExecution(protocolNumber, *arguments, **mapArguments)




