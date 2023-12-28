import json
import socket
import sys
from datetime import datetime
from time import sleep

from account.service.response import AccountLoginResponse
from console_printer.repository.ConsolePrinterRepository import ConsolePrinterRepository
from console_ui.entity.ConsoleUiRoutingState import ConsoleUiRoutingState
from console_ui.repository.ConsoleUiRepositoryImpl import ConsoleUiRepositoryImpl
from console_ui.service.ConsoleUiServiceImpl import ConsoleUiServiceImpl

from tabulate import tabulate


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

                class_name = response.__class__.__name__

                if class_name == "ProgramExitResponse":
                    break

                self.__responseProcessor(response)
                consoleUiService.printMenu()

                consoleUiService.processUserInput(transmitQueue)
            else:
                sleep(0.5)

        print("\033[91mUI Printer Finished!\033[92m")

    def __responseProcessor(self, response):
        print(f"ConsolePrinterRepository - response: {response}")

        class_name = response.__class__.__name__

        if class_name == "AccountRegisterResponse":
            if response.get_is_success() == False:
                print("회원 가입에 실패하였습니다: (중복된 사용자)")
                return

            consoleUiRepository = ConsoleUiRepositoryImpl.getInstance()
            consoleUiRepository.setConsoleUiStateCurrentReadNumber(-1)

        if class_name == "AccountLoginResponse":
            print("Detect Login Response")

            if response.getSessionAccountId() == -1:
                print("로그인에 실패하였습니다: 올바른 정보를 입력하세요!")
                return

            consoleUiRepository = ConsoleUiRepositoryImpl.getInstance()
            consoleUiRepository.setUserSession(response.getSessionAccountId())
            consoleUiRepository.setConsoleUiStateCurrentReadNumber(-1)

        if class_name == "AccountLogoutResponse":
            print("Detect Logout Response")

            if response.getIsSuccess() is False:
                return

            consoleUiRepository = ConsoleUiRepositoryImpl.getInstance()
            consoleUiRepository.clearUserSession()
            consoleUiRepository.setConsoleUiStateCurrentReadNumber(-1)

        if class_name == "AccountDeleteResponse":
            print("Detect Delete Response")

            if response.getIsSuccess() is False:
                return

            print("회원 탈퇴가 완료되었습니다")

            consoleUiRepository = ConsoleUiRepositoryImpl.getInstance()
            consoleUiRepository.clearUserSession()
            consoleUiRepository.setConsoleUiStateCurrentReadNumber(-1)

        if class_name == "ProductListResponse":
            print("Detect Product List Response")

            productList = response.getProductList()

            if productList is None:
                print("현재 등록된 상품이 존재하지 않습니다")
                return

            for product in productList:
                print(
                    f"{product['productId']:<20} {product['name']:<20} {product['price']:<20} {product['registeredAccountId']}")

            consoleUiRepository = ConsoleUiRepositoryImpl.getInstance()
            consoleUiRepository.setConsoleUiStateCurrentReadNumber(-1)

        if class_name == "ProductRegisterResponse":
            print("Detect Product Register Response")

            if response.getId() == -1:
                print("상품 등록 중 문제가 발생하였습니다")
                return

            print("\033[92m\n상품 정보:\033[0m")
            print("\033[92m상품명:\033[93m {}\033[0m".format(response.getName()))
            print("\033[92m상품 가격:\033[93m {} 원\033[0m".format(f"{response.getPrice():,}"))
            print("\033[92m상품 상세 정보:\033[93m {}\033[0m".format(response.getDetails()))
            print("\033[92m상품 등록자 계정:\033[93m {}\033[0m\033[92m".format(response.getAccountId()))

            consoleUiRepository = ConsoleUiRepositoryImpl.getInstance()
            consoleUiRepository.setConsoleUiStateCurrentReadNumber(response.getId())

        if class_name == "ProductReadResponse":
            print("Detect Product Read Response")

            consoleUiRepository = ConsoleUiRepositoryImpl.getInstance()

            if response.getId() == -1:
                print("상품 상세 정보 조회 중 문제가 발생하였습니다")
                consoleUiRepository.setConsoleUiStateCurrentReadNumber(-1)
                consoleUiRepository.saveCurrentRoutingState(ConsoleUiRoutingState.PRODUCT_LIST)
                return

            print("\033[92m\n상품 정보:\033[0m")
            print("\033[92m상품명:\033[93m {}\033[0m".format(response.getName()))
            print("\033[92m상품 가격:\033[93m {} 원\033[0m".format(f"{response.getPrice():,}"))
            print("\033[92m상품 상세 정보:\033[93m {}\033[0m".format(response.getDetails()))
            print("\033[92m상품 등록자 계정:\033[93m {}\033[0m\033[92m".format(response.getAccountId()))

            consoleUiRepository.setConsoleUiStateCurrentReadNumber(response.getId())

        if class_name == "ProductUpdateResponse":
            print("Detect Product Update Response")

            if response.getId() == -1:
                print("상품 상세 정보 조회 중 문제가 발생하였습니다")
                return

            print("\033[92m\n상품 정보:\033[0m")
            print("\033[92m상품명:\033[93m {}\033[0m".format(response.getName()))
            print("\033[92m상품 가격:\033[93m {} 원\033[0m".format(f"{response.getPrice():,}"))
            print("\033[92m상품 상세 정보:\033[93m {}\033[0m".format(response.getDetails()))
            print("\033[92m상품 등록자 계정:\033[93m {}\033[0m\033[92m".format(response.getAccountId()))

            consoleUiRepository = ConsoleUiRepositoryImpl.getInstance()
            consoleUiRepository.setConsoleUiStateCurrentReadNumber(response.getId())

        if 'OrderListResponse' in response:
            print("Detect Order List Response")
            orderList = response['OrderListResponse']

            if orderList is None:
                print("주문 내역이 존재하지 않습니다")
                return

            table = tabulate(orderList, headers='keys', showindex=False, tablefmt='fancy_grid')
            print(table)

        if class_name == "OrderRegisterResponse":
            print("Detect Order Register Response")

            if response.getIsSuccess() is False:
                return

            print("선택한 상품 주문이 완료되었습니다")




def __checkUserSession(self):
        consoleUiRepository = ConsoleUiRepositoryImpl.getInstance()
        consoleUiRepository.getUserSession()

