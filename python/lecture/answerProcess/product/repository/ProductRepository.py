import abc


class ProductRepository(abc.ABC):

    @abc.abstractmethod
    def save(self, account):
        pass



