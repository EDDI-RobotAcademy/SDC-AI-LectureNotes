from dataclasses import dataclass

from account.entity.Account import Account


@dataclass
class AccountRegisterRequest:
    __accountId: str
    __password: str

    def toAccount(self):
        return Account(self.__accountId, self.__password)

    def __init__(self, accountId=None, password=None, **kwargs):
        if accountId is not None and password is not None:
            self.__accountId = accountId
            self.__password = password
        elif "__accountId" in kwargs and "__password" in kwargs:
            self.__accountId = kwargs["__accountId"]
            self.__password = kwargs["__password"]

    @classmethod
    def createFromTuple(cls, inputTuple):
        return cls(*inputTuple)

    def getAccountId(self):
        return self.__accountId

