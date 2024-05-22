import errno
from socket import socket
from time import sleep

from receiver.repository.ReceiverRepository import ReceiverRepository
from account.service.response.AccountRegisterResponse import AccountRegisterResponse
from account.service.response.AccountLoginResponse import AccountLoginResponse
from account.service.response.AccountLogoutResponse import AccountLogoutResponse
from account.service.response.AccountDeleteResponse import AccountDeleteResponse

from product.service.response.ProductListResponse import ProductListResponse
from product.service.response.ProductRegisterResponse import ProductRegisterResponse
from product.service.response.ProductReadResponse import ProductReadResponse
from product.service.response.ProductUpdateResponse import ProductUpdateResponse
from product.service.response.ProductDeleteResponse import ProductDeleteResponse

from order.service.response.OrderRegisterResponse import OrderRegisterResponse


from program.service.response.ProgramExitResponse import ProgramExitResponse


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
    def receiveCommand(self, clientSocketObject, lock, receiveQueue, finishQueue):
        clientSocket = clientSocketObject.getSocket()
        print(f"receiver: is it exist -> {clientSocket}")

        while True:
            try:
                # 소켓으로 전송된 데이터 수신
                data = clientSocket.recv(1024)

                if not data:
                    clientSocket.close()
                    break

                decodedData = data.decode()
                print("\033[91m수신된 정보:\033[0m\033[92m", decodedData)
                responseObject = eval(decodedData)

                receiveQueue.put(responseObject)

                class_name = responseObject.__class__.__name__

                if class_name == "ProgramExitResponse":
                    break

            except socket.error as exception:
                if exception.errno == errno.EWOULDBLOCK:
                    pass

            finally:
                sleep(0.5)

        print("\033[91mReceiver Finished!\033[92m")

        finishQueue.put(True)
