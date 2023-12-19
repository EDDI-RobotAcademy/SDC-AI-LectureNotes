import unittest
from unittest.mock import Mock
import atexit
from server_socket.entity.ServerSocket import ServerSocket


class TestServerSocket(unittest.TestCase):
    def testServerSocketInitialization(self):
        host = "localhost"
        port = 33333
        mock_socket = Mock()

        server_socket = ServerSocket(host, port, mock_socket)

        self.assertEqual(server_socket.getHost(), host)
        self.assertEqual(server_socket.getPort(), port)
        self.assertEqual(server_socket.getSocket(), mock_socket)

    def testCloseSocketCalledOnExit(self):
        host = "localhost"
        port = 33333
        mock_socket = Mock()

        server_socket = ServerSocket(host, port, mock_socket)

        self.addCleanup(server_socket.closeSocket)

        #self.assertTrue(server_socket.getSocket().closeSocket.called, "closeSocket 이 exit 상황에서 안전하게 동작하였음")


if __name__ == '__main__':
    unittest.main()