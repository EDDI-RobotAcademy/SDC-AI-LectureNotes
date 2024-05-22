import abc


class OrderService(abc.ABC):
    @abc.abstractmethod
    def orderList(self):
        pass

    @abc.abstractmethod
    def orderRegister(self):
        pass

