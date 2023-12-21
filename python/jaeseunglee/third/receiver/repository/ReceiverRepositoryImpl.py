import errno
from socket import socket
from time import sleep

from receiver.repository.ReceiverRepository import ReceiverRepository


class ReceiverRepositoryImpl(ReceiverRepository):
    __instance = None

    def __new__(cls):
        if cls.__instance is None:
            cls.__instance = super().__new__(cls)
        return cls.__instance

    def __init__(self):
        print("ReceiverRepositoryImpl 생성자 호출")

    @classmethod
    def getInstance(cls):
        if cls.__instance is None:
            cls.__instance = cls()
        return cls.__instance

    # 클라이언트 소켓에 수신
    def receiveCommand(self, clientSocketObject, lock):
        clientSocket = clientSocketObject.getSocket()
        print(f"receiver: is it exist -> {clientSocket}")

        while True:
            try:
                # 소켓으로 전송된 데이터 수신
                data = clientSocket.recv(1024)

                if not data:
                    clientSocket.closeSocket()
                    break

                print(f'수신된 정보: {data.decode()}')

            # except socket.error as exception:
            except Exception as exception:
                # if exception.errno == errno.EWOULDBLOCK:
                    pass

            finally:
                sleep(0.5)


