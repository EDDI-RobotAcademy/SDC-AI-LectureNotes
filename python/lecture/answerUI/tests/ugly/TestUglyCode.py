import ast
import json
import socket
import unittest
from unittest.mock import patch, Mock

from utility.keyboard.KeyboardInput import KeyboardInput


class TestUlgyCode(unittest.TestCase):
    def testRequestFormatter(self):
        sendProtocol = 1
        request = '(b\'btest\\n\', b\'btest\\n\')'
        print(f"request: {request}")

        requestTuple = ast.literal_eval(request)
        if not isinstance(requestTuple, tuple) or len(requestTuple) != 2:
            raise ValueError("Invalid request format")

        sendingRequest = {
            'accountId': requestTuple[0].decode().strip(),
            'password': requestTuple[1].decode().strip()
        }

        combinedRequestData = {
            'protocol': sendProtocol,
            'data': sendingRequest,
        }

        combinedRequestDataString = json.dumps(combinedRequestData)
        print(f"Combined Request Data String: {combinedRequestDataString}")

        self.assertIn('"protocol":', combinedRequestDataString)
        self.assertIn('"data":', combinedRequestDataString)

    def testEvalClassGeneration(self):
        class TestAccountRegisterResponse:
            def __init__(self, __isSuccess):
                self.__isSuccess = __isSuccess

            def getIsSuccess(self):
                return self.__isSuccess

        data = "TestAccountRegisterResponse(_TestAccountRegisterResponse__isSuccess=True)"
        responseBbject = eval(data)

        isSuccessValue = responseBbject.getIsSuccess()

        print(f'Extracted __isSuccess value: {isSuccessValue}')


if __name__ == '__main__':
    unittest.main()
