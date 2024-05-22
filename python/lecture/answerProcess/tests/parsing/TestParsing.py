import json
import unittest
import re

from account.entity.Account import Account
from account.repository.AccountRepositoryImpl import AccountRepositoryImpl
from mysql.MySQLDatabase import MySQLDatabase

import ast


class TestParsing(unittest.TestCase):
    def setUp(self):
        mysqlDatabase = MySQLDatabase.getInstance()
        mysqlDatabase.connect()

    def testParsing(self):
        receivedRequest = b'1,(b\'btest\\n\', b\'btest\\n\')'

        decodedRequest = receivedRequest.decode('utf-8')
        print(f'수신된 정보: {decodedRequest}')

        requestComponents = decodedRequest.split(',')

        receivedRequestProtocolNumber = requestComponents[0]
        print(f"프로토콜 번호: {receivedRequestProtocolNumber}")

        if len(requestComponents) > 1:
            for i, element in enumerate(requestComponents[1:]):
                # cleanedElement = element.strip().strip("(b'").strip("', )").rstrip("\\n")
                # print(f"후속 정보 {i + 1}: {cleanedElement}")

                byteLiteralMatch = re.search(r"b'(.+)'", element)

                if byteLiteralMatch:
                    byteLiteral = byteLiteralMatch.group(1)
                    decodedElement = byteLiteral.encode('utf-8').decode('unicode_escape')
                    # cleanedElement = decodedElement.rstrip("\\n")
                    # cleanedElement = decodedElement.replace("\\n", "")
                    cleanedElement = decodedElement.strip()
                    print(f"후속 정보 {i + 1}: {cleanedElement}")

    def testOtherParsing(self):
        receivedRequest = b'1,(b\'hohoho\\n\', b\'a,2,f.\\n\')'

        decodedRequest = receivedRequest.decode('utf-8')
        print(f'수신된 정보: {decodedRequest}')

        requestComponents = decodedRequest.split(',')

        receivedRequestProtocolNumber = requestComponents[0]
        print(f"프로토콜 번호: {receivedRequestProtocolNumber}")

        if len(requestComponents) > 1:
            for i, element in enumerate(requestComponents[1:]):
                # cleanedElement = element.strip().strip("(b'").strip("', )").rstrip("\\n")
                # print(f"후속 정보 {i + 1}: {cleanedElement}")

                byteLiteralMatch = re.search(r"b'(.+)'", element)

                if byteLiteralMatch:
                    byteLiteral = byteLiteralMatch.group(1)
                    decodedElement = byteLiteral.encode('utf-8').decode('unicode_escape')
                    # cleanedElement = decodedElement.rstrip("\\n")
                    # cleanedElement = decodedElement.replace("\\n", "")
                    cleanedElement = decodedElement.strip()
                    print(f"후속 정보 {i + 1}: {cleanedElement}")

    def testDictionaryParsing(self):
        receivedData = '{"protocol": 1, "data": {"__accountId": "testsddf", "__password": ";\'l\'lldd"}}'

        receivedDict = json.loads(receivedData)

        protocolNumber = receivedDict["protocol"]
        data = receivedDict["data"]

        print(f"protocolNumber: {protocolNumber}")
        print(f"data: {data}")


if __name__ == '__main__':
    unittest.main()

