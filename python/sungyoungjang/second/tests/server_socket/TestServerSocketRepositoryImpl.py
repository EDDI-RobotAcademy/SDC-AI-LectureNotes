import socket
import unittest
from unittest.mock import patch

from server_socket.repository.ServerSocketRepositoryImpl import ServerSocketRepositoryImpl


class TestServerSocketRepositoryImpl(unittest.TestCase):
    def setUp(self):
        self.serverSocketRepository = ServerSocketRepositoryImpl()

    def testCreatSocketInitialized(self):
        host = 'localhost'
        port = 33333

        with patch('socket.socket') as mock_socket:
            self.serverSocketRepository.create(host, port)

            mock_socket.assert_called_once_with(socket.AF_INET, socket.SOCK_STREAM)

    def testCreateReturnServerSocketInstance(self):
        host = 'localhost'
        port = 33333

        with patch('socket.socket') as mock_socket:
            serverSocket = self.serverSocketRepository.create(host, port)

            self.assertIsNotNone(serverSocket)
            self.assertEqual(serverSocket.getHost(), host)
            self.assertEqual(serverSocket.getPort(), port)
            self.assertEqual(serverSocket.getSocket(), mock_socket.return_value)

if __name__ == '__main__':
    unittest.main()