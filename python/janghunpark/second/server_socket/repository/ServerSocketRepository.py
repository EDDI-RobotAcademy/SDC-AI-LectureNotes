import abc


class ServerSocketRepository(abc.ABC):
    @abc.abstractmethod
    def create(self, host, port):
        pass

    @abc.abstractmethod
    def setSocketOption(self, apiControlLevel, optionName):
        pass
