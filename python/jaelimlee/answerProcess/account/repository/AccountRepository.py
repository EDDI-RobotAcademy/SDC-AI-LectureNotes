import abc


class AccountRepository(abc.ABC):
    @abc.abstractmethod
    def save(self):
        pass

    @abc.abstractmethod
    def save(self, account):
        pass

