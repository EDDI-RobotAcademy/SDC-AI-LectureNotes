import abc


class ResponseGeneratorService(abc.ABC):

    @abc.abstractmethod
    def findResponseGenerator(self, protocolNumber):
        pass

    @abc.abstractmethod
    def generateAccountRegisterResponse(self, arguments):
        pass

