class AccountRegisterResponse:
    def __init__(self, __isSuccess):
        self.__isSuccess = __isSuccess

    def get_is_success(self):
        return self.__isSuccess
