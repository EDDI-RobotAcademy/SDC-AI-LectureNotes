import socket
from time import sleep

from server_socket.service.ServerSocketServiceImpl import ServerSocketServiceImpl
from utility.IPAddressBindSupporter import IPAddressBindSupporter

# __init__py. = 이 파일은 기본적으로 python package 인 것을 인식
if __name__ == '__main__':
    print(f'ip: {IPAddressBindSupporter.getIPAddress()}')
    print(f'ip: {IPAddressBindSupporter.getLocalIPAddress()}')
    # Server Socket : 컴퓨터 네트워크에서 프로세스 간 통신을 가능하게 하는 역할
    # Server Socket 이 수행하는 주요 기능은 다음과 같음
    # 1. 연결 수락 (acceptConnection) : 클라이언트 요청을 수락하고 통신 가능한 새로운 소켓 형성
    # 2. 포트 바인딩 (bindPort) : 특정 포트에 바인딩되어 클라이언트가 해당 포트를 통해 연결할 수 있도록 함
    # 3. 듣기 (listening) : 클라이언트의 연결 요청을 대기
    # 4. 통신 (communicating) : 클라이언트와 연결 이후 데이터를 주고 받을 수 있도록 함
    serverSocketService = ServerSocketServiceImpl()
    # host, port 정보를 바탕으로 서버 소켓 생성
    serverSocketService.createServerSocket("localhost", 33333)
    # 서버 소켓 옵션 설정 ; 필요한 이유는 아래와 같음
    # 예기치 못한 상황이 발생하여 서버가 꺼졌더라도 기존에 사용하던 IP 와 Port 번호를 재사용
    # 소켓 자체의 옵션을 제어 가능 - 추가적인 학습 필요
    serverSocketService.setSocketOption(socket.SOL_SOCKET, socket.SO_REUSEADDR)
    # host 와 port 정보를 가지고 33333 포트에 바인딩
    serverSocketService.bindServerSocket()
    # 서버 동시 접속자 수 제한
    serverSocketService.setServerListenNumber(5)
    # 일단 튕겨내는 접속 없이 blocking 을 막아 놓음 (false)
    serverSocketService.setBlockingOperation()

    while True:
        try:
            serverSocketService.acceptClientSocket()
        except socket.error:
            sleep(0.5)