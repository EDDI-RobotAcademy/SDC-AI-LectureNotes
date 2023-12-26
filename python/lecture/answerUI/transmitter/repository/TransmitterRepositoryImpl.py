import json
import socket
from datetime import datetime
from time import sleep

from console_ui.repository.ConsoleUiRepositoryImpl import ConsoleUiRepositoryImpl
from custom_protocol.repository.CustomProtocolRepositoryImpl import CustomProtocolRepositoryImpl
from request_generator.service.RequestGeneratorServiceImpl import RequestGeneratorServiceImpl
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
        requestGeneratorService = RequestGeneratorServiceImpl.getInstance()
        # ConsoleUiRepository = ConsoleUiRepositoryImpl.getInstance()

        while True:
            with lock:
                try:
                    protocolAndSessionId = transmitQueue.get(block=True)
                    sendProtocol = protocolAndSessionId['protocolNumber']
                    sessionId = protocolAndSessionId['sessionId']
                    print(f"Transmitter typeof(sendProtocol) = {type(sendProtocol)}")
                    print(f"Transmitter sendProtocol = {sendProtocol}")
                    print(f"Transmitter sessionId = {sessionId}")
                    request = customProtocolRepository.execute(sendProtocol)
                    print(f"Transmitter Request from repository: {request}")

                    # sessionId = ConsoleUiRepository.acquireAccountSessionId()
                    # print(f"Transmitter sessionId: {sessionId}")

                    requestGenerator = requestGeneratorService.findRequestGenerator(sendProtocol)
                    print(f"Transmitter Request Generator: {requestGenerator}")

                    if sendProtocol == 5:
                        sendingRequest = requestGenerator(None)
                    elif sessionId is None:
                        sendingRequest = requestGenerator(request)
                    else:
                        sendingRequest = requestGenerator(sessionId)

                    print(f"Transmitter finish to generate request: {sendingRequest}")

                    if sendProtocol == 5:
                        combinedRequestData = {
                            'protocol': sendProtocol
                        }
                    else:
                        combinedRequestData = {
                            'protocol': sendProtocol,
                            'data': sendingRequest,
                        }

                    combinedRequestDataString = json.dumps(combinedRequestData)

                    print(f"transmitter: will be send - {combinedRequestDataString}")

                    clientSocket.sendall(combinedRequestDataString.encode())

                    print('{} command 전송 [{}]'.format(datetime.now(), sendProtocol))

                except (socket.error, BrokenPipeError) as exception:
                    print(f"사용자 연결 종료")
                    return None

                except socket.error as exception:
                    print(f"전송 중 에러 발생: str{exception}")

                except Exception as exception:
                    print(f"transmitter: 원인을 알 수 없는 에러가 발생하였습니다: {str(exception)}")

                finally:
                    sleep(0.5)


