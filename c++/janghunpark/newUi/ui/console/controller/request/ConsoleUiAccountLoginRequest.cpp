//
// Created by eddi on 23. 12. 8.
//
#include <iostream>
#include "ConsoleUiAccountLoginRequest.h"

ConsoleUiAccountLoginRequest::ConsoleUiAccountLoginRequest() {}

ConsoleUiAccountLoginRequest::ConsoleUiAccountLoginRequest(std::string id, std::string pw) {}

void ConsoleUiAccountLoginRequest::printConsoleUiAccountLoginRequest(ConsoleUiAccountLoginRequest request) {
    std::cout << "id는요: " << request.id << std::endl;
    std::cout << "pw는요: " << request.pw << std::endl;
}