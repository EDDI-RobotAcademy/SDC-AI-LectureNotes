import abc


class ServerSocketService(abc.ABC):
    @abc.abstractmethod
    def createServerSocket(self, host, port):
        pass

    @abc.abstractmethod
    def setSocketOption(self, apiControlLevel, OptionName):
        pass

    @abc.abstractmethod
    def bindServerSocket(self):
        pass

    @abc.abstractmethod
    def setServerListenNumber(self, howManyAccessHere):
        pass

    @abc.abstractmethod
    def setBlockingOperation(self):
        pass

    @abc.abstractmethod
    def setBlockingOperation(self):
        pass

    @abc.abstractmethod
    def acceptClientSocket(self):
        pass

