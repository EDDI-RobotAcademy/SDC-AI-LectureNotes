import abc


class ClientSocketRepository(abc.ABC):
    @abc.abstractmethod
    def create(self, host, port):
        pass

    @abc.abstractmethod
    def connectionToTargetHost(self):
        pass

    @abc.abstractmethod
    def setBlockingOperation(self):
        pass

    @abc.abstractmethod
    def getClientSocket(self):
        pass
