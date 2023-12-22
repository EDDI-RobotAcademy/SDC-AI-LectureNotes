import socket
from datetime import datetime
from time import sleep

from custom_protocol.repository.CustomProtocolRepositoryImpl import CustomProtocolRepositoryImpl
from transmitter.repository.TransmitterRepository import TransmitterRepository


class TransmitterRepositoryImpl(TransmitterRepository):
    __instance = None

    def __new__(cls):
        if cls.__instance is None:
            cls.__instance = super().__new__(cls)
        return cls.__instance

    def __init__(self):
        print("TransmitterRepositoryImpl 생성자 호출")

    @classmethod
    def getInstance(cls):
        if cls.__instance is None:
            cls.__instance = cls()
        return cls.__instance

    def transmitCommand(self, clientSocketObject, lock, transmitQueue):
        clientSocket = clientSocketObject.getSocket()
        customProtocolRepository = CustomProtocolRepositoryImpl.getInstance()

        while True:
            with lock:
                try:
                    sendProtocol = transmitQueue.get(block=True)
                    request = customProtocolRepository.execute(sendProtocol)
                    print(f"Request from repository: {request}")

                    combinedRequest = f"{sendProtocol},{request}"
                    print(f"transmitter: will be send - {combinedRequest}")

                    clientSocket.sendall(combinedRequest.encode())


                    print('{} command 전송 [{}]'.format(datetime.now(), sendProtocol))

                except (socket.error, BrokenPipeError) as exception:
                    print(f"사용자 연결 종료")
                    return None

                except socket.error as exception:
                    print(f"전송 중 에러 발생: str{exception}")

                except Exception as exception:
                    print(f"transmitter: 원인을 알 수 없는 에러가 발생하였습니다: str{exception}")

                finally:
                    sleep(0.5)


