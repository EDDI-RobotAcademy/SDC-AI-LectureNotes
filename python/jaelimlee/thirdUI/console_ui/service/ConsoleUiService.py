import abc


class ConsoleUiService(abc.ABC):
    @abc.abstractmethod
    def processUserInput(self, transmitQueue):
        pass