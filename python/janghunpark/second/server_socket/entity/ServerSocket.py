# 외부 요청을 받는 역할
import atexit


class ServerSocket(object):
    def __init__(self, host, port, socket):
        self.__host = host
        self.__port = port
        self.__socket = socket

        # c++ 로 치면 소멸자
        # 자동 소켓 종료
        atexit.register(self.closeSocket)

    def getHost(self):
        return self.__host

    def getPort(self):
        return self.__port

    def getSocket(self):
        return self.__socket

    def closeSocket(self):
        print("Server socket is closed.")
        self.__socket.close()
