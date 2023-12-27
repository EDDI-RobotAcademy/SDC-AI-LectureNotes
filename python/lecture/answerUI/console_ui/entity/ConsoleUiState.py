from console_ui.entity.ConsoleUiRoutingState import ConsoleUiRoutingState


class ConsoleUiState():

    def __init__(self):
        self.__currentRoutingState = ConsoleUiRoutingState.NOTHING
        self.__currentReadNumber = -1

    def setCurrentRoutingState(self, currentState):
        self.__currentRoutingState = currentState

    def getCurrentRoutingState(self):
        return self.__currentRoutingState

    def getCurrentReadNumber(self):
        return self.__currentReadNumber

    def setCurrentReadNumber(self, currentReadNumber):
        self.__currentReadNumber = currentReadNumber

