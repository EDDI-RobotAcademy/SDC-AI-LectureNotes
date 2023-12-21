import abc


class CustomProtocolRepository(abc.ABC):
    @abc.abstractmethod
    def register(self, protocolNumber, pointerOfFunction):
        pass

    @abc.abstractmethod
    def execute(self, protocolNumber, *arguments, **mapArguments):
        pass

