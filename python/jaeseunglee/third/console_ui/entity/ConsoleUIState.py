class ConsoleUIState():

    def __init__(self):
        self.__currentRoutingState = None
        # self.__currentReadPageNumber = None

    def setCurrentRoutingState(self, currentState):
        self.__currentRoutingState = currentState

    def getCurrentRoutingState(self):
        return self.__currentRoutingState