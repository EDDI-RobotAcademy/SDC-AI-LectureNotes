import sys

from program.repository.ProgramRepository import ProgramRepository


class ProgramRepositoryImpl(ProgramRepository):
    __instance = None

    def __new__(cls):
        if cls.__instance is None:
            cls.__instance = super().__new__(cls)
        return cls.__instance

    # def __init__(self):
    #     print("ProgramRepositoryImpl 초기화 동작")

    @classmethod
    def getInstance(cls):
        if cls.__instance is None:
            cls.__instance = cls()
        return cls.__instance

    def createProgramExitForm(self):
        print("프로그램을 종료합니다")
        return