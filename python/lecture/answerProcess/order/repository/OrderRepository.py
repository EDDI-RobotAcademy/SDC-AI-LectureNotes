import abc


class OrderRepository(abc.ABC):

    @abc.abstractmethod
    def save(self, order):
        pass



