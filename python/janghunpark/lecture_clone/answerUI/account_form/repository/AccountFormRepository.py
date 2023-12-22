import abc


class AccountFormRepository(abc.ABC):
    @abc.abstractmethod
    def createAccountRegisterForm(self):
        pass
