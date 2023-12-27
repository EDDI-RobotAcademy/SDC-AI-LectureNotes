class AccountLogoutResponse:
    def __init__(self, __isSuccess):
        self.__isSuccess = __isSuccess

    def getIsSuccess(self):
        return self.__isSuccess

