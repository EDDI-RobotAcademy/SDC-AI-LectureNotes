class AccountLoginResponse:
    def __init__(self, __sessionAccountId):
        self.__sessionAccountId = __sessionAccountId

    def getSessionAccountId(self):
        return self.__sessionAccountId

