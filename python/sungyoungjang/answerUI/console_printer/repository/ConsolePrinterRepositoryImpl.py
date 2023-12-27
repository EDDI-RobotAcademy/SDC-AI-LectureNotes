import socket
import sys
from datetime import datetime
from time import sleep

from account.service.response import AccountLoginResponse
from console_printer.repository.ConsolePrinterRepository import ConsolePrinterRepository
from console_ui.repository.ConsoleUiRepositoryImpl import ConsoleUiRepositoryImpl
from console_ui.service.ConsoleUiServiceImpl import ConsoleUiServiceImpl


class ConsolePrinterRepositoryImpl(ConsolePrinterRepository):
    __instance = None
    __sessionAccountId = -1

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



    def printConsoleUi(self, transmitQueue, receiveQueue):

        consoleUiService = ConsoleUiServiceImpl.getInstance()
        # consoleUiService.printMenu(self.__sessionAccountId)
        consoleUiService.printMenu()
        consoleUiService.processUserInput(transmitQueue)

        while True:
            if not receiveQueue.empty():
                response = receiveQueue.get()
                print(f"ConsolePrinterRepository Received response: {response}")

                self.__responseProcessor(response)
                # sessionAccountId = self.__checkUserSession()
                consoleUiService.printMenu()

                consoleUiService.processUserInput(transmitQueue)
            else:
                sleep(0.5)

    def __responseProcessor(self, response):
        print(f"ConsolePrinterRepository - response: {response}")

        class_name = response.__class__.__name__

        if class_name == "AccountRegisterResponse":
            if response.get_is_success() == False:
                print("회원 가입에 실패하였습니다: (중복된 사용자)")
                return

        if class_name == "AccountLoginResponse":
            print("Detect Login Response")

            if response.getSessionAccountId() == -1:
                print("로그인에 실패하였습니다: 올바른 정보를 입력하세요!")
                return

            consoleUiRepository = ConsoleUiRepositoryImpl.getInstance()
            consoleUiRepository.setUserSession(response.getSessionAccountId())

        if class_name == "AccountLogoutResponse":
            print("Detect Logout Response")

            if response.getIsSuccess() is False:
                return

            consoleUiRepository = ConsoleUiRepositoryImpl.getInstance()
            consoleUiRepository.clearUserSession()

        if class_name == "AccountDeleteResponse":
            print("Detect Delete Response")

            if response.getIsSuccess() is False:
                return

            print("회원 탈퇴가 완료되었습니다")

            # consoleUiRepository = ConsoleUiRepositoryImpl.getInstance()
            # consoleUiRepository.clearUserSession()

        if class_name == "ProductListResponse":
            print("Detect Product List Response")

            productList = response.getProductList()

            if productList is None:
                print("현재 등록된 상품이 존재하지 않습니다")
                return

            for product in productList:
                print(
                    f"{product['productId']:<20} {product['name']:<20} {product['price']:<20} {product['registeredAccountId']}")

    def __checkUserSession(self):
        consoleUiRepository = ConsoleUiRepositoryImpl.getInstance()
        consoleUiRepository.getUserSession()

