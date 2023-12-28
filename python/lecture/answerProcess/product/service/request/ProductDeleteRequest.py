from dataclasses import dataclass

from product.entity.Product import Product


@dataclass
class ProductDeleteRequest:
    __id: int
    __sessionId: int

    def __init__(self, id=0, sessionId=-1, **kwargs):
        if "__id" in kwargs and "__sessionId" in kwargs:
            self.__id = kwargs["__id"]
            self.__sessionId = kwargs["__sessionId"]
        else:
            self.__id = id
            self.__sessionId = sessionId

    @classmethod
    def createFromTuple(cls, inputTuple):
        return cls(*inputTuple)

    def getSessionId(self):
        return self.__sessionId

    def getId(self):
        return self.__id

