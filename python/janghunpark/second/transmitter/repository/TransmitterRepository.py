import abc


class TransmitterRepository(abc.ABC):
    @abc.abstractmethod
    def transmitCommand(self, clientSocket):
        pass

    @abc.abstractmethod
    def getTransmitQueue(self):
        pass
