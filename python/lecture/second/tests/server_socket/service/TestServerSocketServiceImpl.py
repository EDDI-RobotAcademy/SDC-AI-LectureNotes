import socket
import unittest
from unittest.mock import patch, Mock

from server_socket.entity.ServerSocket import ServerSocket
from server_socket.repository.ServerSocketRepositoryImpl import ServerSocketRepositoryImpl
from server_socket.service.ServerSocketServiceImpl import ServerSocketServiceImpl


class TestServerSocketServiceImpl(unittest.TestCase):
    def testCreateServerSocketCallsRepositoryCreate(self):
        host = "localhost"
        port = 8080

        # patch.object의 경우 ServerSocketRepositoryImpl의 create 매서드를 Mock 매서드로 대체
        # ServerSocketRepositoryImpl의 create을 mock_create으로 대체하였다는 뜻
        with patch.object(ServerSocketRepositoryImpl, 'create') as mock_create:
            service_impl = ServerSocketServiceImpl()
            service_impl.createServerSocket(host, port)

            mock_create.assert_called_once_with(host, port)

    def test_createServerSocket_returns_server_socket_instance(self):
        host = "localhost"
        port = 8080
        expected_server_socket = ServerSocket(host, port, Mock())

        # 위와 동일하게 patch.object를 사용하기 때문에 기본적인 형식은 동일합니다.
        # return_value 라는 것이 새롭게 추가되어 있는 것을 볼 수 있습니다.
        # 실제로는 Repository를 통해 확보한 정보가 리턴되지만
        # Fake로 작업하는 것이기 때문에 실제 형태가 나오지 않습니다.
        # 그러므로 그 결과값이 나왔다 가정 했을 때
        # 그것을 return_value=expected_server_socket 이라 가정한 것입니다.
        with patch.object(ServerSocketRepositoryImpl, 'create', return_value=expected_server_socket):
            service_impl = ServerSocketServiceImpl()
            result = service_impl.createServerSocket(host, port)

            self.assertEqual(result, expected_server_socket)


if __name__ == '__main__':
    unittest.main()
