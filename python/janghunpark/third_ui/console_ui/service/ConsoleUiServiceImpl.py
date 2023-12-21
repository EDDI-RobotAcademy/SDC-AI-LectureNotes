from console_ui.service.ConsoleUiService import ConsoleUiService
from utility.keyboard.KeyboardInput import KeyboardInput


class ConsoleUiServiceImpl(ConsoleUiService):
    __instance = None

    # new : allocator
    # c++ 에서 new 와 같이 객체에 메모리 할당
    def __new__(cls, repository):
        # instance 가 없다면
        if cls.__instance is None:
            # super() : 클래스 상속
            cls.__instance = super().__new__(cls)
            # 추후에 repository 를 service 에 귀속시키기 위한 방식
            cls.__instance.__repository = repository
        return cls.__instance

    # init : constructor
    # 메모리를 할당하지 않기 때문에 인스턴스를 생성할 수 없음
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


