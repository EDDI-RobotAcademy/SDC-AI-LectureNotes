import abc


class ProductService(abc.ABC):

    @abc.abstractmethod
    def listProduct(self):
        pass

    @abc.abstractmethod
    def registerProduct(self):
        pass

    @abc.abstractmethod
    def readProduct(self):
        pass

    @abc.abstractmethod
    def updateProduct(self):
        pass

    @abc.abstractmethod
    def deleteProduct(self):
        pass

    @abc.abstractmethod
    def searchProduct(self):
        pass



