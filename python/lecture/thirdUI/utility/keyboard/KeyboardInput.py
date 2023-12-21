class KeyboardInput:
    @staticmethod
    def getKeyboardIntegerInput():
        while True:
            try:
                userInput = int(input("원하는 선택지를 입력하세요: "))
                return userInput

            except ValueError:
                print("숫자값을 입력해야 합니다!")

