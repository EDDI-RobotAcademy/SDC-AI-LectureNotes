import abc


class ReceiverRepository(abc.ABC):
    @abc.abstractmethod
    def receiveCommand(self, clientSocketObject, lock):
        pass
