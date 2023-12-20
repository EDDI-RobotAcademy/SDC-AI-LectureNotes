import abc


class ClientSocketService(abc.ABC):
    @abc.abstractmethod
    def createClientSocket(self, host, port):
        pass

    @abc.abstractmethod
    def setBlockingOperation(self):
        pass


