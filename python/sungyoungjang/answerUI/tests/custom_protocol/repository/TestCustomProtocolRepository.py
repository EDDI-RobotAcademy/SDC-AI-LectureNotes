import socket
import unittest
from unittest.mock import patch, Mock

from custom_protocol.repository.CustomProtocolRepositoryImpl import CustomProtocolRepositoryImpl


class TestCustomProtocolRepository(unittest.TestCase):
    def setUp(self):
        self.customProtocolRepository = CustomProtocolRepositoryImpl()

    def callPuppy(self):
        print("멍! 멍!")

    # 결론적으로 별 1개는 여러 정보들을 동시 다발적으로 받습니다.
    # C/C++ 관점에서 생각해보고 싶다면
    # 구조체에 감싸여진 정보가 한 번에 넘어온다 생각해도 됩니다만
    # python에서는 python 스타일을 사용하는 것이 좋습니다.
    def callPuppies(self, *arguments):
        for argument in arguments:
            print(argument)

    # 아래와 같이 Key 값과 Value 값이 같이 있는 것을 Map이라고 합니다.
    # '**' 의 경우엔 C/C++과 다르게 이중 포인터가 아닌 Map 데이터를 받을 때 사용합니다.
    def callDictionaryPuppies(self, **mapArguments):
        for key, value in mapArguments.items():
            print(f"{key}: {value}")

    # 우리 귀여운 puppy 같은 형식이 있습니다.
    # python에서는 test를 할 때 반드시 매서드 명 맨 앞에 'test' 를 붙여야합니다.
    def testSingletonCreation(self):
        print("CustomProtocolRepository: 싱글톤 생성 테스트")

        testFirstInstance = CustomProtocolRepositoryImpl.getInstance()
        testSecondInstance = CustomProtocolRepositoryImpl.getInstance()

        testFirstInstance.register(3, self.callPuppy)
        testFirstInstance.execute(3)

        testSecondInstance.register(2, self.callPuppies)
        testFirstInstance.execute(2, "진돗개", "푸들", "셰퍼드")

        testFirstInstance.register(1, self.callDictionaryPuppies)
        testSecondInstance.execute(1, dog1="우리예쁜강아지", dog2="어린강아지", dog3="들자란강아지")

        self.assertIs(self.customProtocolRepository, testFirstInstance)
        self.assertIs(self.customProtocolRepository, testSecondInstance)
        self.assertIs(testFirstInstance, testSecondInstance)

    # def testCreateReturnsServerSocketInstance(self):
    #     print("Repository: 서버 소켓 생성 이후 인스턴스 반환 테스트")
    #
    #     host = config('HOST')
    #     port = int(config('PORT'))
    #
    #     with patch('socket.socket') as mock_socket:
    #         serverSocket = self.serverSocketRepository.create(host, port)
    #
    #         self.assertIsNotNone(serverSocket)
    #         self.assertEqual(serverSocket.getHost(), host)
    #         self.assertEqual(serverSocket.getPort(), port)
    #         self.assertEqual(serverSocket.getSocket(), mock_socket.return_value)


if __name__ == '__main__':
    unittest.main()
