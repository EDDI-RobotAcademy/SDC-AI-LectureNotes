import multiprocessing
import socket
from datetime import datetime
from time import sleep

from transmitter.repository.TransmitterRepository import TransmitterRepository


class TransmitterRepositoryImpl(TransmitterRepository):
    __instance = None
    __transmitQueue = multiprocessing.Queue()

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

    def transmitCommand(self, clientSocket):
        while True:
            try:
                print("transmitter: 응답 준비")
                response = self.__transmitQueue.get()

                if response is not None:
                    print(f"응답할 내용: {response}")
                    clientSocket.sendall(response.encode())

                # clientSocket = clientSocketObject.getSocket()
                # clientSocket.sendall(sendMessage.encode())
                # print('{} command 전송 [{}]'.format(datetime.now(), sendMessage))

            except (socket.error, BrokenPipeError) as exception:
                print(f"사용자 연결 종료")
                return None

            except socket.error as exception:
                print(f"전송 중 에러 발생: str{exception}")

            except Exception as exception:
                print("원인을 알 수 없는 에러가 발생하였습니다")

            finally:
                sleep(0.5)

    def getTransmitQueue(self):
        return self.__transmitQueue
