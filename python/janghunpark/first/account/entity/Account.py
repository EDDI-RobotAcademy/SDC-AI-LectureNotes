class Account:
    # Account::Account(std::string accountId, std::string password)
    #                                   : accountId(accountId), password(password) {}
    def __init__(self, accountId, password):
        self.__account_id = accountId
        self.__password = password

    def getAccountId(self):
        return self.__account_id

    def setAccountId(self, accountId):
        self.__account_id = accountId

    def getPassword(self):
        return self.__password

    def setPassword(self, password):
        self.__password = password

    # print(instance) 할 때 자동으로 아래의 내용을 출력함
    def __str__(self):
        return f"Account[{self.__account_id}:{self.__password}]"