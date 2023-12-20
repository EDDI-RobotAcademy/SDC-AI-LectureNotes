import abc

class TaskManageService(abc.ABC):
    @abc.abstractmethod
    def createTransmitTask(self, lock):
        pass

    @abc.abstractmethod
    def createReceiveTask(self, lock):
        pass
