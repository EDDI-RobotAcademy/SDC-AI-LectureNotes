from console_ui.entity.ConsoleUiRoutingState import ConsoleUiRoutingState
from console_ui.entity.ConsoleUiState import ConsoleUiState
from console_ui.repository.ConsoleUiRepository import ConsoleUiRepository


class ConsoleUiRepositoryImpl(ConsoleUiRepository):
    __instance = None
    __session = None

    __uiMenuTable = {}
    __uiSelectDecisionTable = {}

    def __new__(cls):
        if cls.__instance is None:
            cls.__instance = super().__new__(cls)
            cls.__instance.__uiMenuTable[ConsoleUiRoutingState.NOTHING.value] = cls.__instance.__printDefaultMenu
            cls.__instance.__uiSelectDecisionTable[ConsoleUiRoutingState.NOTHING.value] = cls.__instance.__selectDecisionFromUserChoice
        return cls.__instance

    def __init__(self):
        print("ConsoleUiRepository 초기화 동작")

        self.__consoleUiState = ConsoleUiState()

    @classmethod
    def getInstance(cls):
        if cls.__instance is None:
            cls.__instance = cls()
        return cls.__instance

    def saveCurrentRoutingState(self, currentState):
        self.__consoleUiState.setCurrentRoutingState(currentState)

    def acquireCurrentRoutingState(self):
        return self.__consoleUiState.getCurrentRoutingState()

    # 현재 시점에 약간 애매함
    def saveRequestFormToTransmitQueue(self):
        pass

    def findRoutingStateFromUserChoice(self, userChoice):
        currentRoutingState = self.__consoleUiState.getCurrentRoutingState()
        print(f"currentRoutingState: {currentRoutingState}")
        print(f"currentRoutingState.value: {currentRoutingState.value}")
        selectDecider = self.__uiSelectDecisionTable[currentRoutingState.value]
        print(f"selectDecider: {selectDecider}")
        return selectDecider(userChoice)

    def __selectDecisionFromUserChoice(self, userChoice):
        print(f"__selectDicisionFromUserChoice() - userChoiceType: {type(userChoice)}")
        if self.__session is None:
            if userChoice == 1:
                return ConsoleUiRoutingState.ACCOUNT_REGISTER

            if userChoice == 2:
                return "This is case 2"

            if userChoice == 3:
                return "This is case 3"

            if userChoice == 4:
                return "This is case 4"


    def printMenu(self):
        currentRoutingState = self.__consoleUiState.getCurrentRoutingState()

        menuPrinter = self.__uiMenuTable[currentRoutingState.value]
        menuPrinter()

    def __printDefaultMenu(self):
        if self.__session is None:
            print("1. 회원 가입")
            print("2. 로그인")
            print("3. 상품 리스트 조회")
            print("4. 종료")
            return

        print("1. 로그아웃")
        print("2. 상품 리스트 조회")
        print("3. 주문 내역 조회")
        print("4. 종료")


