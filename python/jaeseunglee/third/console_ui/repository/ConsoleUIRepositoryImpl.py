from console_ui.entity.ConsoleUIState import ConsoleUIState
from console_ui.repository.ConsoleUIRepository import ConsoleUIRepository


class ConsoleUIRepositoryImpl(ConsoleUIRepository):
    __instance = None
    __consoleUIState = None

    def __new__(cls):
        if cls.__instance is None:
            cls.__instance = super().__new__(cls)
        return cls.__instance

    def __init__(self):
        print("ConsoleUIRepository 초기화 동작")
        self.__consoleUIState = ConsoleUIState()

    @classmethod
    def getInstance(cls):
        if cls.__instance is None:
            cls.__instance = cls()
        return cls.__instance

    def saveCurrentRoutingState(self, currentState):
        self.__consoleUIState.setCurrentRoutingState(currentState)

    def acquireCurrentRoutingState(self):
        self.__consoleUIState.getCurrentRoutingState()

