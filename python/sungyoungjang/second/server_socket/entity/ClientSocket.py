class ClientSocket(object):
    def __init__(self, clientSocket, clientAddress):
        self.__clientSocket = clientSocket
        self.__clientAddress = clientAddress

    def getClientSocket(self):
        return self.__clientSocket

    def getClientAddress(self):
        return self.__clientAddress
