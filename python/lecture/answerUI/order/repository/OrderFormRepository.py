import abc


class OrderFormRepository(abc.ABC):
    @abc.abstractmethod
    def createOrderRegisterForm(self):
        pass

    @abc.abstractmethod
    def createOrderListForm(self):
        pass
    

