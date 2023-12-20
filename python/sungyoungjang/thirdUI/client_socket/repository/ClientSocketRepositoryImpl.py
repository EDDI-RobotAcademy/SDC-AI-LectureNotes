import socket

from decouple import config

from client_socket.entity.ClientSocket import ClientSocket
from client_socket.repository.ClientSocketRepository import ClientSocketRepository


class ClientSocketRepositoryImpl(ClientSocketRepository):
    __instance = None

    def __new__(cls):
        if cls.__instance is None:
            cls.__instance = super().__new__(cls)
        return cls.__instance

    def __init__(self):
        print("ClientSocketRepository 생성자 호출")
        self.__clientSocket = None

    def create(self, host, port):
        socketObject = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.__clientSocket = ClientSocket(host, port, socketObject)
        return self.__clientSocket

    def connectionToTargetHost(self):
        if not self.__clientSocket:
            self.create(config('TARGET_HOST'), int(config('PORT')))

        clientSocketObject = self.__clientSocket.getSocket()

        try:
            clientSocketObject.connect(
                # tuple은 소괄호로 감싸면 하나의 묶음이 됩니다
                # 저번 시간에 살짝 언급했던 struct로 묶는 방식입니다.
                (
                    self.__clientSocket.getHost(),
                    self.__clientSocket.getPort()
                )
            )

        except ConnectionRefusedError:
            print(f"{self.__clientSocket.getHost()}:{self.__clientSocket.getPort()} 에 연결 중 거절되었습니다")

        except Exception as exception:
            print(f"연결 중 에러 발생: {str(exception)}")

    def setBlockingOperation(self):
        socketObject = self.__clientSocket.getSocket()
        socketObject.setblocking(False)




