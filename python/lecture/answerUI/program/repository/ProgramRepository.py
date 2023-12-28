import abc


class ProgramRepository(abc.ABC):
    @abc.abstractmethod
    def createProgramExitForm(self):
        pass

