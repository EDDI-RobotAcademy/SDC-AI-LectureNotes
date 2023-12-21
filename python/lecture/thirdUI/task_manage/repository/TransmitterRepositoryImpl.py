import socket
from datetime import datetime
from time import sleep

from task_manage.repository.TransmitterRepository import TransmitterRepository


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

    # 클라이언트 소켓에서 송신
    def transmitCommand(self, clientSocketObject, lock):
        while True:
            with lock:
                try:
                    pass
                    # protocol

                    sendMessage = "참 쉽죠 ?"
                    clientSocket = clientSocketObject.getSocket()

                    # 실제 연결된 클라이언트에 데이터 송신
                    clientSocket.sendall(sendMessage.encode())

                    print('{} command 전송 [{}]'.format(datetime.now(), sendMessage))

                except (socket.error, BrokenPipeError) as exception:
                    print(f"사용자 연결 종료")
                    return None

                except socket.error as exception:
                    print(f"전송 중 에러 발생: str{exception}")

                except Exception as exception:
                    print("원인을 알 수 없는 에러가 발생하였습니다")

                finally:
                    sleep(0.5)


