import os


class KeyboardInput:
    @classmethod
    def getKeyboardIntegerInput(cls, outputString):
        while True:
            try:
                print(f"{outputString} ", end="")
                userInput = os.read(0, 1024)
                return int(userInput)

            except ValueError:
                print("숫자값을 입력해야 합니다!")

            except EOFError:
                pass

    @classmethod
    def getKeyboardInput(cls, outputString):
        while True:
            try:
                print(f"{outputString} ", end="")
                userInput = os.read(0, 1024)
                return userInput

            except EOFError:
                pass

