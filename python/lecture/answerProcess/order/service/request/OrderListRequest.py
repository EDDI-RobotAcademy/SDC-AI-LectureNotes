class OrderListRequest:
    __sessionId: int

    def __init__(self, sessionId=-1, **kwargs):
        if "__sessionId" in kwargs:
            self.__sessionId = kwargs["__sessionId"]
        else:
            self.__sessionId = sessionId

    @classmethod
    def createFromTuple(cls, inputTuple):
        return cls(*inputTuple)

    def getSessionId(self):
        return self.__sessionId

