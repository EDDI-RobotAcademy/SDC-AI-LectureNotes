from dataclasses import dataclass

from product.entity.Product import Product


@dataclass
class ProductUpdateRequest:
    __id: int
    __name: str
    __price: int
    __details: str
    __sessionId: int

    def toProduct(self):
        return Product(self.__id, self.__name, self.__price, self.__details, self.__sessionId)

    def __init__(self, id=-1, name=None, price=0, details=None, sessionId=-1, **kwargs):
        if name is not None and details is not None:
            self.__id = id
            self.__name = name
            self.__price = price
            self.__details = details
            self.__sessionId = sessionId
        elif "__name" in kwargs and "__details" in kwargs:
            self.__id = kwargs["__id"]
            self.__name = kwargs["__name"]
            self.__price = kwargs["__price"]
            self.__details = kwargs["__details"]
            self.__sessionId = kwargs["__sessionId"]

    @classmethod
    def createFromTuple(cls, inputTuple):
        return cls(*inputTuple)

    def getSessionId(self):
        return self.__sessionId

    def getName(self):
        return self.__name

    def getPrice(self):
        return self.__price

    def getDetails(self):
        return self.__details

    def getId(self):
        return self.__id

