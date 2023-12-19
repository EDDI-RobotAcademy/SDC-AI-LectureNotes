import abc


class ServerSocketService(abc.ABC):
    # abc.abstractmethod = virtual class 라는 것을 알려주는 것
    @abc.abstractmethod
    def createServerSocket(self, host, port):
        pass

    @abc.abstractmethod
    def setSocketOption(self, apiControlLevel, optionName):
        pass
