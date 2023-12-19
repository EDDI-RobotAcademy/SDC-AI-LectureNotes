import abc


class ServerSocketRepository(abc.ABC):
    @abc.abstractmethod
    def create(self, host, port):
        pass

    @abc.abstractmethod
    def setSocketOption(self, apiControlLevel, OptionName):
        pass

    @abc.abstractmethod
    def bindServerSocket(self):
        pass

    @abc.abstractmethod
    def setListenNumber(self, howManyAccessHere):
        pass

    @abc.abstractmethod
    def acceptClientSocket(self):
        pass
