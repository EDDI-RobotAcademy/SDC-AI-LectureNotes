import socket
import sys
from datetime import datetime
from time import sleep

from console_printer.repository.ConsolePrinterRepository import ConsolePrinterRepository
from console_ui.service.ConsoleUiServiceImpl import ConsoleUiServiceImpl


class ConsolePrinterRepositoryImpl(ConsolePrinterRepository):
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



    def printConsoleUi(self, transmitQueue, receiveQueue):

        consoleUiService = ConsoleUiServiceImpl.getInstance()
        consoleUiService.processUserInput(transmitQueue)

        while True:
            if not receiveQueue.empty():
                response = receiveQueue.get()
                print(f"Received response: {response}")

                consoleUiService.processUserInput(transmitQueue)
            else:
                sleep(0.5)



