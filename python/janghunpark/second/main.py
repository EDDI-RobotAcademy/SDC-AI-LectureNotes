# 추상화
from server_socket.service.ServerSocketServiceImpl import ServerSocketServiceImpl


# __init__py. = 이 파일은 기본적으로 python package 인 것을 인식
if __name__ == '__main__':
    serverSocketService = ServerSocketServiceImpl()
    serverSocketService.createServerSocket("localhost", 33333)