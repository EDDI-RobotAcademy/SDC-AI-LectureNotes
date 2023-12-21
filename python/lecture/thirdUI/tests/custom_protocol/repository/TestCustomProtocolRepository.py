import socket
import unittest
from unittest.mock import patch, Mock

from custom_protocol.repository.CustomProtocolRepositoryImpl import CustomProtocolRepositoryImpl


class TestCustomProtocolRepository(unittest.TestCase):
    def setUp(self):
        self.customProtocolRepository = CustomProtocolRepositoryImpl()

    def callPuppy(self):
        print("멍! 멍!")

    # 우리 귀여운 puppy 같은 형식이 있습니다.
    # python에서는 test를 할 때 반드시 매서드 명 맨 앞에 'test' 를 붙여야합니다.
    def testSingletonCreation(self):
        print("CustomProtocolRepository: 싱글톤 생성 테스트")

        testFirstInstance = CustomProtocolRepositoryImpl.getInstance()
        testSecondInstance = CustomProtocolRepositoryImpl.getInstance()

        testFirstInstance.register(3, self.callPuppy)
        testFirstInstance.execute(3)

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
