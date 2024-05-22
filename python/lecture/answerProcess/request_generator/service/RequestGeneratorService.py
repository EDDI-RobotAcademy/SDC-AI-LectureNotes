import abc


class RequestGeneratorService(abc.ABC):

    @abc.abstractmethod
    def findRequestGenerator(self, protocolNumber):
        pass

    @abc.abstractmethod
    def generateAccountRegisterRequest(self, arguments):
        pass

