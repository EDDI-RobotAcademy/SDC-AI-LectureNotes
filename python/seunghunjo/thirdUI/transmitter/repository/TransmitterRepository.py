import abc


class TransmitterRepository(abc.ABC):
    @abc.abstractmethod
    def transmitCommand(self, clientSocketObject, lock):
        pass
