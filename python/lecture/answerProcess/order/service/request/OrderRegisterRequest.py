from dataclasses import dataclass


@dataclass
class OrderRegisterRequest:
    __productId: int
    __sessionId: int

    def __init__(self, productId=-1, sessionId=-1, **kwargs):
        if "__productId" in kwargs and "__sessionId" in kwargs:
            self.__productId = kwargs["__productId"]
            self.__sessionId = kwargs["__sessionId"]
        else:
            self.__productId = productId
            self.__sessionId = sessionId

    @classmethod
    def createFromTuple(cls, inputTuple):
        return cls(*inputTuple)

    def getSessionId(self):
        return self.__sessionId

    def getProductId(self):
        return self.__productId

