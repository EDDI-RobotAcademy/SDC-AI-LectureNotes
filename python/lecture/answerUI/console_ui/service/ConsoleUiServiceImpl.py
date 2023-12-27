from console_ui.entity.ConsoleUiRoutingState import ConsoleUiRoutingState
from console_ui.service.ConsoleUiService import ConsoleUiService
from utility.keyboard.KeyboardInput import KeyboardInput


class ConsoleUiServiceImpl(ConsoleUiService):
    __instance = None

    def __new__(cls, repository):
        if cls.__instance is None:
            cls.__instance = super().__new__(cls)
            cls.__instance.__repository = repository
        return cls.__instance

    def __init__(self, repository):
        print("ConsoleUiServiceImpl 생성자 호출")

    @classmethod
    def getInstance(cls, repository=None):
        if cls.__instance is None:
            cls.__instance = cls(repository)
        return cls.__instance

    def printMenu(self):
        print("\033[91m현재 상태에 따른 메시지를 출력합니다\033[0m\033[92m")

        print("")
        print(f"ConsoleUiService - consoleUiRepository: {self.__repository}")

        self.__repository.printMenu()

    def processUserInput(self, transmitQueue):
        userChoice = KeyboardInput.getKeyboardIntegerInput("원하는 번호를 입력하세요:")
        print(f"ConsoleUiService - 입력된 숫자: {userChoice}")
        # selectedRoutingState = self.__repository.findRoutingStateFromUserChoice(userChoice)
        # print(f"처리된 상태값: {selectedRoutingState}")
        # self.__repository.saveCurrentRoutingState(selectedRoutingState)

        # 필요하다면 여기 중간에 몇 가지 작업들이 더 처리 될 수 있습니다.
        convertedUserChoice = self.__repository.convertUserChoiceToProperRouting(userChoice)
        print(f"ConsoleUiService - convertedUserChoice: {convertedUserChoice}")

        sessionId = None
        sessionObject = self.__repository.acquireSession()
        if sessionObject:
            sessionId = sessionObject.get_session_id()
            print(f"ConsoleUiService - sessionObject: {sessionObject}, sessionId: {sessionId}")

        currentRoutingState = self.__repository.acquireCurrentRoutingState()
        if currentRoutingState is ConsoleUiRoutingState.NOTHING:
            print(f"RoutingState Nothing: {currentRoutingState}")
            if userChoice == 1 or userChoice == 5:
                self.__repository.clearUserSession()

        productReadNo = self.__repository.getConsoleUiState().getCurrentReadNumber()
        print("\033[91mConsoleUiService - productReadNo: ",productReadNo)
        print("\033[92m", end="")

        transmitData = {'protocolNumber': convertedUserChoice, 'sessionId': sessionId, 'productReadNo': productReadNo}
        self.__repository.decisionRoutingState(convertedUserChoice)

        transmitQueue.put(transmitData)


