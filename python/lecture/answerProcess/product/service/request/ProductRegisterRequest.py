from dataclasses import dataclass

from product.entity.Product import Product


@dataclass
class ProductRegisterRequest:
    __name: str
    __price: int
    __details: str
    __sessionId: int

    def toProduct(self):
        return Product(self.__name, self.__price, self.__details, self.__sessionId)

    def __init__(self, name=None, price=0, details=None, sessionId=-1, **kwargs):
        if name is not None and details is not None:
            self.__name = name
            self.__price = price
            self.__details = details
            self.__sessionId = sessionId
        elif "__name" in kwargs and "__details" in kwargs:
            self.__name = kwargs["__name"]
            self.__price = kwargs["__price"]
            self.__details = kwargs["__details"]
            self.__sessionId = kwargs["__sessionId"]

    @classmethod
    def createFromTuple(cls, inputTuple):
        return cls(*inputTuple)



