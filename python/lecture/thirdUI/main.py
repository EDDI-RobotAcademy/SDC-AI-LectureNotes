import multiprocessing
import socket
from time import sleep
from decouple import config
# pip3 install python-decouple

from client_socket.repository.ClientSocketRepositoryImpl import ClientSocketRepositoryImpl
from client_socket.service.ClientSocketServiceImpl import ClientSocketServiceImpl
from custom_protocol.service.CustomProtocolServiceImpl import CustomProtocolServiceImpl
from task_manage.repository.TaskManageRepositoryImpl import TaskManageRepositoryImpl
from task_manage.service.TaskManageServiceImpl import TaskManageServiceImpl


def initServerSocketDomain():
    clientSocketRepository = ClientSocketRepositoryImpl()
    ClientSocketServiceImpl(clientSocketRepository)


def initTaskManageDomain():
    taskManageRepository = TaskManageRepositoryImpl()
    TaskManageServiceImpl(taskManageRepository)


def initEachDomain():
    initServerSocketDomain()
    initTaskManageDomain()


# 시나리오:
# 강아지 구매하고 싶은데 리스트 좀 보여줘! -> 전송
# 가지고 있는 강아지 리스트 응답         <- 수신
def registerProtocol():
    customProtocolService = CustomProtocolServiceImpl.getInstance()

    # customProtocolService.registerCustomProtocol(0, )


if __name__ == '__main__':
    initEachDomain()
    registerProtocol()

    clientSocketService = ClientSocketServiceImpl.getInstance()

    # 하위에 보이는 config는 실제로 IP 주소, 비밀번호, PORT 번호를 환경 변수로 관리하기 위해 사용합니다.
    # 왜 이렇게 관리해야 할까요 ? 결국 외부에 위의 정보가 노출되면 보안에 취약해지기 때문임
    clientSocketService.createClientSocket(config('TARGET_HOST'), int(config('PORT')))
    clientSocketService.connectToTargetHost()

    # clientSocketService.setBlockingOperation()

    # 현재 시나리오에서
    # 입력에 대한 요청을 처리하는 Transmitter
    # 응답에 대한 출력을 처리하는 Receiver
    # 위와 같은 태스크들을 작성합니다.
    # 실제로는 더 조각조각 내는 것이 좋긴합니다.
    taskManageService = TaskManageServiceImpl.getInstance()

    lock = multiprocessing.Lock()
    # 1. Transmitter 태스크를 생성 요청
    # 2. Transmitter 태스크 객체 구성
    # 3. 구성된 객체의 특정 동작을 취하도록 Transmitter 구동
    taskManageService.createTransmitTask(lock)

    # 1. Receiver 태스크 생성 요청
    # 2. Receiver 태스크 객체 구성
    # 3. Receiver 객체의 특정 동작을 취하도록 만듬
    taskManageService.createReceiveTask(lock)
    taskManageService.createPrinterTask()

    while True:
        try:
            # serverSocketService.acceptClientSocket()
            # print("main: 나도 별개의 Task 야")
            sleep(0.5)

        except socket.error:
            sleep(0.5)


# 보편적으로 서비스를 제공하는 입장에 놓여 있으면 Server(서버)
# 서비스를 받는 입장에 있으면 Client(클라이언트) 라고 합니다.
# 앞으로 만들 UI는 현재 작성한 Server에게 요청(Request)를 합니다.
# 그럼 UI는 Server가 준 응답(Response)를 가지고 지 나름대로의 기준으로 처리를 합니다.
