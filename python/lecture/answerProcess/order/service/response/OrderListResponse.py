class OrderListResponse:
    def __init__(self, orderList):
        self.__orderList = orderList

    def toDict(self):
        return {'OrderListResponse': self.__orderList}
