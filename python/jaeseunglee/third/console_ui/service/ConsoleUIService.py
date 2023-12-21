import abc


class ConsoleUIService(abc.ABC):
    @abc.abstractmethod
    def processUserInput(self):
        pass