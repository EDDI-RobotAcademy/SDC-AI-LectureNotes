import errno
from socket import socket
from time import sleep

from custom_protocol.repository.CustomProtocolRepositoryImpl import CustomProtocolRepositoryImpl
from receiver.repository.ReceiverRepository import ReceiverRepository
from transmitter.repository.TransmitterRepositoryImpl import TransmitterRepositoryImpl

import re


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

    def receiveCommand(self, clientSocket):
        transmitterRepository = TransmitterRepositoryImpl.getInstance()
        transmitQueue = transmitterRepository.getTransmitQueue()
        customProtocolRepository = CustomProtocolRepositoryImpl.getInstance()

        while True:
            try:
                receivedRequest = clientSocket.recv(1024)

                if not receivedRequest:
                    clientSocket.closeSocket()
                    break

                decodedRequest = receivedRequest.decode('utf-8')
                print(f'수신된 정보: {decodedRequest}')

                requestComponents = decodedRequest.split(',')

                receivedRequestProtocolNumber = requestComponents[0]
                print(f"프로토콜 번호: {receivedRequestProtocolNumber}")

                cleanedElementList = []

                if len(requestComponents) > 1:
                    for i, element in enumerate(requestComponents[1:]):
                        byteLiteralMatch = re.search(r"b'(.+)'", element)

                        if byteLiteralMatch:
                            byteLiteral = byteLiteralMatch.group(1)
                            decodedElement = byteLiteral.encode('utf-8').decode('unicode_escape')
                            cleanedElement = decodedElement.strip()
                            print(f"후속 정보 {i + 1}: {cleanedElement}")

                            cleanedElementList.append(cleanedElement)

                response = customProtocolRepository.execute(int(receivedRequestProtocolNumber), cleanedElementList)
                print(f"response: {response}")

                transmitQueue.put(response)

            except socket.error as exception:
                if exception.errno == errno.EWOULDBLOCK:
                    pass

            finally:
                sleep(0.5)


