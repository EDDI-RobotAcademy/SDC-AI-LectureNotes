import abc


class ProductService(abc.ABC):

    @abc.abstractmethod
    def listProduct(self):
        pass

    @abc.abstractmethod
    def registerProduct(self):
        pass



