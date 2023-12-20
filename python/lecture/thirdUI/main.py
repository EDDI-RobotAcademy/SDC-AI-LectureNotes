import socket
from time import sleep
from decouple import config
# pip3 install python-decouple

from client_socket.repository.ClientSocketRepositoryImpl import ClientSocketRepositoryImpl
from client_socket.service.ClientSocketServiceImpl import ClientSocketServiceImpl


def initServerSocketDomain():
    clientSocketRepository = ClientSocketRepositoryImpl()
    ClientSocketServiceImpl(clientSocketRepository)


def initEachDomain():
    initServerSocketDomain()


if __name__ == '__main__':
    initEachDomain()

    clientSocketService = ClientSocketServiceImpl.getInstance()

    # 하위에 보이는 config는 실제로 IP 주소, 비밀번호, PORT 번호를 환경 변수로 관리하기 위해 사용합니다.
    # 왜 이렇게 관리해야 할까요 ? 결국 외부에 위의 정보가 노출되면 보안에 취약해지기 때문임
    clientSocketService.createClientSocket(config('TARGET_HOST'), int(config('PORT')))
    # serverSocketService.setSocketOption(socket.SOL_SOCKET, socket.SO_REUSEADDR)
    # serverSocketService.bindServerSocket()
    # serverSocketService.setServerListenNumber(1)
    # serverSocketService.setBlockingOperation()
    #
    # while True:
    #     try:
    #         serverSocketService.acceptClientSocket()
    #
    #     except socket.error:
    #         sleep(0.5)


# 보편적으로 서비스를 제공하는 입장에 놓여 있으면 Server(서버)
# 서비스를 받는 입장에 있으면 Client(클라이언트) 라고 합니다.
# 앞으로 만들 UI는 현재 작성한 Server에게 요청(Request)를 합니다.
# 그럼 UI는 Server가 준 응답(Response)를 가지고 지 나름대로의 기준으로 처리를 합니다.
