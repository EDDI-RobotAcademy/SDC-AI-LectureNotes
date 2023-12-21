import abc


class ConsolePrinterRepository(abc.ABC):
    @abc.abstractmethod
    def printConsoleUi(self):
        pass

