import abc


class ProductFormRepository(abc.ABC):
    @abc.abstractmethod
    def createProductListForm(self):
        pass

    @abc.abstractmethod
    def createProductRegisterForm(self):
        pass

