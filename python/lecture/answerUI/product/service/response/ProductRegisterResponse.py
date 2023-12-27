class ProductRegisterResponse:
    def __init__(self, __id, __name, __price, __details, __accountId):
        self.__id = __id
        self.__name = __name
        self.__price = __price
        self.__details = __details
        self.__accountId = __accountId

    def getId(self):
        return self.__id

    def getName(self):
        return self.__name

    def getPrice(self):
        return self.__price

    def getDetails(self):
        return self.__details

    def getAccountId(self):
        return self.__accountId

