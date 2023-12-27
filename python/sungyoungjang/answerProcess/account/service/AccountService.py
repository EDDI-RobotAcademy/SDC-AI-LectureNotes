import abc


class AccountService(abc.ABC):
    @abc.abstractmethod
    def registerAccount(self, *args, **kwargs):
        pass

    @abc.abstractmethod
    def loginAccount(self, *args, **kwargs):
        pass

    @abc.abstractmethod
    def logoutAccount(self, *args, **kwargs):
        pass

    @abc.abstractmethod
    def deleteAccount(self, *args, **kwargs):
        pass

