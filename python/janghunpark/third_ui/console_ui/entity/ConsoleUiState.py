class ConsoleUiState():

    def __init__(self):
        self.__currentRoutingState = None
        # 아래와 같이 현재 상대에 대한 인덱스가 관리되고 있어야 함
        # self.__currentReadNumber = None

    def setCurrentRoutingState(self, currentState):
        self.__currentRoutingState = currentState

    def getCurrentRoutingState(self):
        return self.__currentRoutingState

