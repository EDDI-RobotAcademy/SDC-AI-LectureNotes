from console_ui.entity.ConsoleUiState import ConsoleUiState
from console_ui.repository.ConsoleUiRepository import ConsoleUiRepository


class ConsoleUiRepositoryImpl(ConsoleUiRepository):
    __instance = None

    def __new__(cls):
        if cls.__instance is None:
            cls.__instance = super().__new__(cls)
        return cls.__instance

    def __init__(self):
        print("ConsoleUiRepositoryImpl Initiator Call")
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
