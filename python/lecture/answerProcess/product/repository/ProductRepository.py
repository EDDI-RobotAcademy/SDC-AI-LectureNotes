import abc


class ProductRepository(abc.ABC):

    @abc.abstractmethod
    def findAll(self):
        pass



