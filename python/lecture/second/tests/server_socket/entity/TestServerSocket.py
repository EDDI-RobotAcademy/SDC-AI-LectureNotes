import unittest
from unittest.mock import Mock, patch
import atexit
from server_socket.entity.ServerSocket import ServerSocket


class TestServerSocket(unittest.TestCase):
    def testServerSocketInitialization(self):
        print("Entity: 서버 소켓 생성 테스트")

        host = "localhost"
        port = 33333
        mock_socket = Mock()

        server_socket = ServerSocket(host, port, mock_socket)

        self.assertEqual(server_socket.getHost(), host)
        self.assertEqual(server_socket.getPort(), port)
        self.assertEqual(server_socket.getSocket(), mock_socket)

    def testCloseSocketCalledOnExit(self):
        print("Entity: 서버 소켓 소멸 테스트")

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