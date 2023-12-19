import atexit

class ServerSocket(object):
    def __init__(self, host, port, socket):
        self.__host = host
        self.__port = port
        self.__socket = socket

        atexit.register(self.closeSocket)

    

    def closeSocket(self):
        print("서버 소켓 종료!")
        self.__socket.close()
