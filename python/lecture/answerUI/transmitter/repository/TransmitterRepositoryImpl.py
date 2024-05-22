import json
import socket
from datetime import datetime
from time import sleep

from console_ui.repository.ConsoleUiRepositoryImpl import ConsoleUiRepositoryImpl
from custom_protocol.entity.CustomProtocol import CustomProtocol
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
                    transmitData = transmitQueue.get(block=True)
                    sendProtocol = transmitData['protocolNumber']
                    sessionId = transmitData['sessionId']
                    print(f"Transmitter typeof(sendProtocol) = {type(sendProtocol)}")
                    print(f"Transmitter sendProtocol = {sendProtocol}")
                    print(f"Transmitter sessionId = {sessionId}")
                    request = customProtocolRepository.execute(sendProtocol)
                    print(f"Transmitter Request from repository: {request}")

                    # sessionId = ConsoleUiRepository.acquireAccountSessionId()
                    # print(f"Transmitter sessionId: {sessionId}")

                    requestGenerator = requestGeneratorService.findRequestGenerator(sendProtocol)
                    print("\033[91mTransmitter Request Generator:\033[0m\033[92m", requestGenerator)

                    # TODO: 이 부분을 별도의 Domain으로 빼놓는 것이 더 깔끔함
                    # 숫자 보다 enum 값을 사용하는 것이 가독성 측면에서 더 좋음
                    if sendProtocol == CustomProtocol.PROGRAM_EXIT.value:
                        sendingRequest = requestGenerator(None)
                    elif sendProtocol == CustomProtocol.ORDER_REGISTER.value:
                        sendingRequest = requestGenerator(sessionId, request)
                    elif sendProtocol == 10:
                        sendingRequest = requestGenerator(request)
                    elif sendProtocol == 9:
                        productReadNo = transmitData["productReadNo"]
                        sendingRequest = requestGenerator(sessionId, productReadNo)
                    elif sendProtocol == 8:
                        productReadNo = transmitData["productReadNo"]
                        sendingRequest = requestGenerator(request, sessionId, productReadNo)
                    elif sendProtocol == 7:
                        sendingRequest = requestGenerator(request, sessionId)
                    elif sendProtocol == 6:
                        sendingRequest = requestGenerator(request, sessionId)
                    elif sendProtocol == 5:
                        sendingRequest = requestGenerator(None)
                    elif sessionId is None:
                        sendingRequest = requestGenerator(request)
                    else:
                        sendingRequest = requestGenerator(sessionId)

                    print("\033[91mTransmitter finish to generate request:\033[0m\033[92m", sendingRequest)

                    if sendProtocol == 5 or sendProtocol == CustomProtocol.PROGRAM_EXIT.value:
                        combinedRequestData = {
                            'protocol': sendProtocol
                        }
                    else:
                        combinedRequestData = {
                            'protocol': sendProtocol,
                            'data': sendingRequest,
                        }

                    combinedRequestDataString = json.dumps(combinedRequestData)

                    print("\033[91mtransmitter: will be send -\033[0m\033[92m", combinedRequestDataString)

                    clientSocket.sendall(combinedRequestDataString.encode())

                    print('{} command 전송 [{}]'.format(datetime.now(), sendProtocol))

                    if sendProtocol == CustomProtocol.PROGRAM_EXIT.value:
                        break

                except (socket.error, BrokenPipeError) as exception:
                    print(f"사용자 연결 종료")
                    return None

                except socket.error as exception:
                    print(f"전송 중 에러 발생: str{exception}")

                except Exception as exception:
                    print(f"transmitter: 원인을 알 수 없는 에러가 발생하였습니다: {str(exception)}")

                finally:
                    sleep(0.5)

        print("\033[91mTransmitter Finished!\033[92m")
