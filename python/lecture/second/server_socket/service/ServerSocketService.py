import abc


class ServerSocketService(abc.ABC):
    @abc.abstractmethod
    def createServerSocket(self, host, port):
        pass
