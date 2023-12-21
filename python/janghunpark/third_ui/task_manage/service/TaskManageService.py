import abc

class TaskManageService(abc.ABC):
    @abc.abstractmethod
    def createTransmitTask(self, lock):
        pass

    def createReceiveTask(self, lock):
        pass
