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

    def printMenu(self):
        print("현재 상태에 따른 메시지를 출력합니다")

        self.__repository.printMenu()

    def processUserInput(self, transmitQueue):
        userChoice = KeyboardInput.getKeyboardIntegerInput()
        print(f"입력된 숫자: {userChoice}")
        # selectedRoutingState = self.__repository.findRoutingStateFromUserChoice(userChoice)
        # print(f"처리된 상태값: {selectedRoutingState}")
        # self.__repository.saveCurrentRoutingState(selectedRoutingState)

        # 필요하다면 여기 중간에 몇 가지 작업들이 더 처리 될 수 있습니다.
        transmitQueue.put(userChoice)


