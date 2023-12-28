import abc


class OrderFormRepository(abc.ABC):
    @abc.abstractmethod
    def createOrderRegisterForm(self):
        pass

    

