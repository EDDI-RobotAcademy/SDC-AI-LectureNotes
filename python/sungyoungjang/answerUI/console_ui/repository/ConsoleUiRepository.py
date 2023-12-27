import abc


class ConsoleUiRepository(abc.ABC):

    @abc.abstractmethod
    def saveCurrentRoutingState(self, currentState):
        pass

    @abc.abstractmethod
    def acquireCurrentRoutingState(self):
        pass

    @abc.abstractmethod
    def saveRequestFormToTransmitQueue(self):
        pass

    @abc.abstractmethod
    def printMenu(self):
        pass

    @abc.abstractmethod
    def findRoutingStateFromUserChoice(self, userChoice):
        pass

    @abc.abstractmethod
    def convertUserChoiceToProperRouting(self, userChoice):
        pass

    @abc.abstractmethod
    def acquireSession(self):
        pass

    @abc.abstractmethod
    def acquireAccountSessionId(self):
        pass

    @abc.abstractmethod
    def convertUserChoiceToProperRouting(self, userChoice):
        pass

    @abc.abstractmethod
    def setUserSession(self, sessionId):
        pass

    @abc.abstractmethod
    def clearUserSession(self):
        pass

