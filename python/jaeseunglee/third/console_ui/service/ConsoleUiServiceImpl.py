from console_ui.service.ConsoleUiService import ConsoleUiService
from utility.keyboard.KeyboardInput import KeyboardInput


class ConsoleUiServiceImpl(ConsoleUiService):
    __instance = None

    def __new__(cls, repository):
        if cls.__instance is None:
            cls.__instance = super().__new__(cls)
            cls.__instance.__repository = repository
        return cls.__instance

    def __init__(self, repository):
        print("ConsoleUiServiceImpl 생성자 호출")

    @classmethod
    def getInstance(cls, repository=None):
        if cls.__instance is None:
            cls.__instance = cls(repository)
        return cls.__instance

    def processUserInput(self, transmitQueue):
        print("우리 보호소는 리스트만 볼 수 있습니다!")
        print("0. 강아지 리스트 보기")
        print("1. 프로그램 종료")

        userChoice = KeyboardInput.getKeyboardIntegerInput()
        self.__repository.saveCurrentRoutingState(userChoice)

        # 필요하다면 여기 중간에 몇 가지 작업들이 더 처리 될 수 있습니다.
        transmitQueue.put(userChoice)


