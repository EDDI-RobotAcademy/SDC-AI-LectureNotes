import abc

class TaskManageService(abc.ABC):
    @abc.abstractmethod
    def createTransmitTask(self):
        pass

    @abc.abstractmethod
    def createReceiveTask(self):
        pass