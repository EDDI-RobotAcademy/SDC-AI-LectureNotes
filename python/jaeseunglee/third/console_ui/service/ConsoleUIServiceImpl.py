from console_ui.service.ConsoleUIService import ConsoleUIService


class ConsoleUIServiceImpl(ConsoleUIService):
    __instance = None

    def __new__(cls):
        if cls.__instance is None:
            cls.__instance = super().__new__(cls)
        return cls.__instance

    def __init__(self):
        print("ConsoleUIRepository 초기화 동작")

    @classmethod
    def getInstance(cls):
        if cls.__instance is None:
            cls.__instance = cls()
        return cls.__instance

    def processUserInput(self):
        print("우리 보호소는 리스트만 볼 수 있습니다!")
        print("0. 강아지 리스트 보기")
        print("1. 프로그램 종료")


