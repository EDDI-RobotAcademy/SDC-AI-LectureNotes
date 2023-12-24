import os


class KeyboardInput:
    @staticmethod
    def getKeyboardIntegerInput():
        while True:
            try:
                print("원하는 선택지를 입력하세요: ")
                userInput = os.read(0, 1024)
                return int(userInput)

            except ValueError:
                print("숫자값을 입력해야 합니다!")

            except EOFError:
                pass

