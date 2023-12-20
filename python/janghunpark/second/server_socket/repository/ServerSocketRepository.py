import abc


class ServerSocketRepository(abc.ABC):
    @abc.abstractmethod
    def create(self, host, port):
        pass

    @abc.abstractmethod
    def setSocketOption(self, apiControlLevel, optionName):
        pass

    @abc.abstractmethod
    def bindServerSocket(self):
        pass

    @abc.abstractmethod
    def setServerListenNumber(self, howManyConnections):
        pass

    @abc.abstractmethod
    def setBlockingOperation(self):
        pass

    @abc.abstractmethod
    def acceptClientSocket(self):
        pass