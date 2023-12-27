import json
import unittest
import re

from mysql.MySQLDatabase import MySQLDatabase



class JustForUglyTest(unittest.TestCase):

    def testUgly(self):
        class UglyTestClass:
            def __init__(self, _UglyTestClass__accountId, _UglyTestClass__password):
                self.__accountId = _UglyTestClass__accountId
                self.__password = _UglyTestClass__password

            @classmethod
            def from_dict(cls, data_dict):
                mapping = {
                    '__accountId': '_UglyTestClass__accountId',
                    '__password': '_UglyTestClass__password'
                }
                mapped_data = {mapping[key]: value for key, value in data_dict.items()}
                return cls(**mapped_data)

        data = {'__accountId': 'accountIdTestCase', '__password': 'pass@word'}
        obj = UglyTestClass.from_dict(data)

        print(obj._UglyTestClass__accountId)
        print(obj._UglyTestClass__password)



if __name__ == '__main__':
    unittest.main()

