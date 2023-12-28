import abc


class ProductFormRepository(abc.ABC):
    @abc.abstractmethod
    def createProductListForm(self):
        pass

    @abc.abstractmethod
    def createProductRegisterForm(self):
        pass

    @abc.abstractmethod
    def createProductReadForm(self):
        pass

    @abc.abstractmethod
    def createProductUpdateForm(self):
        pass

    @abc.abstractmethod
    def createProductSearchForm(self):
        pass


