import atexit

class ServerSocket(object):
    def __init__(self, host, port, socket):
        self.__host = host
        self.__port = port
        self.__socket = socket

        atexit.register(self.closeSocket)


    def getHost(self):
        return self.__host

    def getPort(self):
        return self.__port

    def getSocket(self):
        return self.__socket

    def closeSocket(self):
        print("서버 소켓 종료!")
        self.__socket.close()