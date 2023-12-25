import abc


class TransmitterRepository(abc.ABC):
    @abc.abstractmethod
    def transmitCommand(self, clientSocketObject):
        pass

    @abc.abstractmethod
    def getTransmitQueue(self):
        pass
