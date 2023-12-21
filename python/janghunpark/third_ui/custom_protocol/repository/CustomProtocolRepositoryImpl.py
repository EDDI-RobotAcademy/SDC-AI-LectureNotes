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
        print("CustomProtocolRepositoryImpl Initiator Call")
        self.__clientSocket = None

    @classmethod
    def getInstance(cls):
        if cls.__instance is None:
            cls.__instance = cls()
        return cls.__instance

    def notImplemented(self):
        print("This method is not implemented.")

    # python 은 '__' 가 붙으면 무조건 private
    # 외부에서 임의로 protocol 을 변경하지 못하도록 private 로 설정
    # python 스타일에 맞게 타입 추론이 필요
    def __importCustomProtocol(self, protocolNumber, pointerOfFunction):

        # pointerOfFunction 이 실행 가능하다면
        if callable(pointerOfFunction):
            customProtocolTableLength = len(self.__customProtocolTable)

            # customProtocolTableLength 가 충분히 큰지 확인
            # 충분히 크다면 바로 protocolNumber 에 pointerOfFunction 을 대응시킴
            if customProtocolTableLength > protocolNumber + 1:
                # 배열에 집어넣는 방법 (append)
                # self.__customProtocolTable.append(pointerOfFunction)
                self.__customProtocolTable[protocolNumber] = pointerOfFunction
            # 그렇지 않다면 테이블의 길이를 강제로 늘려서 대응시킴
            else:
                self.__customProtocolTable = [0] * (protocolNumber + 1)
                self.__customProtocolTable[protocolNumber] = pointerOfFunction
        else:
            # 위에서 무조건 실행될 것
            print("This is not executable.")


    def register(self, protocolNumber, pointerOfFunction):
        print(f"Protocol number={protocolNumber} is matched with handler: {pointerOfFunction}")

        self.__importCustomProtocol(protocolNumber, pointerOfFunction)

    def __protocolTableExecution(self, protocolNumber, *arguments, **mapArguments):
        # 아무 기능도 탑재되지 않은 protocol 이 아닌 경우
        if self.__customProtocolTable[protocolNumber] is not self.notImplemented:
            pointerOfFunction = self.__customProtocolTable[protocolNumber]
            # pointerOfFunction 에 구조체와 Key & Value set 를 전달함
            result = pointerOfFunction(*arguments, **mapArguments)
            return result

        print(f"Protocol number={protocolNumber} is not registered.")

    def execute(self, protocolNumber, *arguments, **mapArguments):
        print(f"Protocol number={protocolNumber} Execution!")

        # for key, value in mapArguments.items():
        #     print(f"{key}: {value}")

        self.__protocolTableExecution(protocolNumber, *arguments, **mapArguments)




