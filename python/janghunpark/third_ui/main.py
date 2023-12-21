# 보편적으로 서비스를 제공하는 입장에 놓여 있으면 Server, 서비스를 받는 입장에 있으면 Client
# 결론적으로 UI 는 Client 라고도 함
# UI 는 Server 에 Request 를 한 뒤 돌려 받은 Response 를 가지고 자기 나름의 기준 대로 처리
# 결국 여기(UI)에서 second 에 있는 서버로 붙어야 함
# pip3 install python-decouple : .env 에 중요한 정보를 따로 관리하기 위한 tool
import multiprocessing
import socket
from time import sleep
from decouple import config

# 롤 클라이언트라고 생각을 해보자. 결국 이 프로젝트는 로그인하는 화면이나 다름 없다.
# 그러면 내가 실행을 하면 서버 접속이 되고 (target host, port 가 저장되어 있기 때문)
# 로그인 정보를 입력하면 네트워크를 타고 날아가 서버에서 인증을 받고 응답을 받은 것을 기반으로 다음 세션으로 넘어감

from client_socket.repository.ClientSocketRepositoryImpl import ClientSocketRepositoryImpl
from client_socket.service.ClientSocketServiceImpl import ClientSocketServiceImpl
from console_ui.repository.ConsoleUiRepositoryImpl import ConsoleUiRepositoryImpl
from console_ui.service.ConsoleUiServiceImpl import ConsoleUiServiceImpl
from custom_protocol.service.CustomProtocolServiceImpl import CustomProtocolServiceImpl
from task_manage.repository.TaskManageRepositoryImpl import TaskManageRepositoryImpl
from task_manage.service.TaskManageServiceImpl import TaskManageServiceImpl


def initServerSocketDomain():
    clientSocketRepository = ClientSocketRepositoryImpl()
    ClientSocketServiceImpl(clientSocketRepository)


def initTaskManageDomain():
    taskManageRepository = TaskManageRepositoryImpl()
    TaskManageServiceImpl(taskManageRepository)


def initConsoleUoDomain():
    consoleUiRepository = ConsoleUiRepositoryImpl()
    ConsoleUiServiceImpl(consoleUiRepository)


def initEachDomain():
    initServerSocketDomain()
    initTaskManageDomain()
    initConsoleUoDomain()


def registerProtocol():
    customProtocolService = CustomProtocolServiceImpl.getInstance()


if __name__ == '__main__':
    initEachDomain()
    registerProtocol()

    clientSocketService = ClientSocketServiceImpl.getInstance()

    clientSocketService.createClientSocket(config('TARGET_HOST'), int(config('PORT')))
    clientSocketService.connectToTargetHost()

    # clientSocketService.setBlockingOperation()

    # 실제 작업을 할 때 명확하게 역할을 분리하여
    # 입력에 대한 요청을 처리하는 Transmitter
    # 응답에 대한 출력을 처리하는 Receiver
    # 위와 같은 Task 들을 작성합니다.
    # 실제로는 더 조각조각 내는 것이 좋습니다.
    taskManageService = TaskManageServiceImpl.getInstance()

    # 공유 자원에 대한 혼선이 생기지 않도록 하기 위한 장치
    lock = multiprocessing.Lock()
    transmitQueue = multiprocessing.Queue()
    # 1. Transmitter 태스크를 생성 요청
    # 2. Transmitter 태스크 객체 구성
    # 3. 구성된 객체의 특정 동작을 취하도록 Transmitter 구동
    taskManageService.createTransmitTask(lock, transmitQueue)

    # 1. Receiver 태스크를 생성 요청
    # 2. Receiver 태스크 객체 구성
    # 3. 구성된 객체의 특정 동작을 취하도록 Receiver 구동
    taskManageService.createReceiveTask(lock)
    taskManageService.createPrinterTask(transmitQueue)

    while True:
        try:
            # serverSocketService.acceptClientSocket()
            # print("main: 나도 별개의 Task 야")
            sleep(5.0)

        except socket.error:
            sleep(0.5)