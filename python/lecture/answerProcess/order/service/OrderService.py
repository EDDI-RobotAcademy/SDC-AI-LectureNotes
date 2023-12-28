import abc


class OrderService(abc.ABC):
    @abc.abstractmethod
    def orderRegister(self):
        pass

