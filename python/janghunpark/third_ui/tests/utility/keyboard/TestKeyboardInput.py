import socket
import unittest
from unittest.mock import patch, Mock

from utility.keyboard.KeyboardInput import KeyboardInput


class TestKeyboardInput(unittest.TestCase):
    def testKeyboardInput(self):
        print("키보드 입력 테스트")

        result = KeyboardInput.getKeyboardIntegerInput()
        print(f"result = {result}")


if __name__ == '__main__':
    unittest.main()
