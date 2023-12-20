import socket
import unittest
from unittest.mock import patch, Mock

from server_socket.repository.ServerSocketRepositoryImpl import ServerSocketRepositoryImpl


class TestServerSocketRepositoryImpl(unittest.TestCase):
    def setUp(self):
        self.serverSocketRepository = ServerSocketRepositoryImpl()

    def testCreateSocketInitialized(self):
        host = "localhost"
        port = 33333

        # patch('socket.socket') as mock_socket 의 경우
        # socket 모듈의 socket 클래스를 가상(mock) 객체로 대체
        # 소위 Mocking 한다고 하는데 가상으로 만들어놓고 사용하는 것입니다.
        # 실제 Repository에 있는 socket.socket을 Mocking한 것
        with patch('socket.socket') as mock_socket:
            self.serverSocketRepository.create(host, port)

            # 오직 한 번만 실행되는지 검증
            mock_socket.assert_called_once_with(socket.AF_INET, socket.SOCK_STREAM)

    def testCreateReturnsServerSocketInstance(self):
        host = "localhost"
        port = 33333

        with patch('socket.socket') as mock_socket:
            serverSocket = self.serverSocketRepository.create(host,port)

            self.assertIsNotNone(serverSocket)
            self.assertEqual(serverSocket.getHost(), host)
            self.assertEqual(serverSocket.getPort(), port)
            self.assertEqual(serverSocket.getSocket(), mock_socket.return_value)

if __name__ == '__main__':
    unittest.main()