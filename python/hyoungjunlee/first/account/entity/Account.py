class Account:

    def __init__(self,accountId,password):
        self.__accountId = accountId
        self.__password = password

    def getAccountId(self):
        return self.__accountId

    def setAccountId(self, accountId):
        self.__accountId = accountId

    def getPassword(self):
        return self.__password

    def setPassword(self, password):
        self.__password = password

    def __str__(self):
        return f"Account[{self.__accountId}:{self.__password}]"