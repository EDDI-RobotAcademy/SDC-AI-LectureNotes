import unittest
from unittest.mock import Mock, patch
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

        with patch.object(server_socket, '_ServerSocket__socket') as mock_close:
            atexit._run_exitfuncs()

            # Assert
            mock_close.close.assert_called_once()


if __name__ == '__main__':
    unittest.main()