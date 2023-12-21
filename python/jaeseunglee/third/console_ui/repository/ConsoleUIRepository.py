import abc


class ConsoleUIRepository(abc.ABC):
    @abc.abstractmethod
    def saveCurrentRoutingState(self, currentState):
        pass
    @abc.abstractmethod
    def acquireCurrentRoutingState(self):
        pass