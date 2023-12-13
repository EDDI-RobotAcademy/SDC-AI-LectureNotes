//
// Created by junghwan on 23. 12. 6.
//

#include <iostream>

#include "ConsoleUiController.h"
#include "../service/ConsoleUiService.h"

#include "../user_keyboard/user_keyboard_input.h"

//ConsoleUiController::ConsoleUiController() {}

ConsoleUiController::ConsoleUiController(std::shared_ptr<ConsoleUiServiceImpl> consoleUiService) : consoleUiService(consoleUiService) { }

void ConsoleUiController::uiAccountLogin() {
    std::cout << "ConsoleUiController: Start Login" << std::endl;
//    void *requestForm;

    consoleUiService->makeAccountLoginRequestForm();

//    BoardController boardController;
//    boardController.boardList;
}

void ConsoleUiController::uiAccountRegister() {
    std::cout << "회원가입을 시작합니다." << std::endl;

    // 회원가입 서비스 호출
}

void ConsoleUiController::uiBoardList() {
    std::cout << "게시판을 정렬합니다." << std::endl;

    // 게시판 정렬 서비스 호출
}

void ConsoleUiController::uiBoardWrite() {
    std::cout << "게시판을 정렬합니다." << std::endl;

    // 게시물 작성 서비스 호출
}

void ConsoleUiController::uiBoardRead() {
    std::cout << "게시물을 읽습니다." << std::endl;

    // 게시물 조회 서비스 호출
}

void ConsoleUiController::uiBoardEdit() {
    std::cout << "게시물을 수정합니다." << std::endl;

    // 게시물 수정 서비스 호출
}

void ConsoleUiController::uiBoardRemove() {
    std::cout << "게시물을 삭제합니다." << std::endl;

    // 게시물 삭제 서비스 호출
}

void ConsoleUiController::uiEngineStart() {
    std::string initialAccountCommand;
    user_keyboard_input initialInput;
    std::cout << "게시판 최초 화면" << std::endl;
    std::cout << "0. Login" << std::endl;
    std::cout << "1. Register" << std::endl;
    std::cout << "2. Exit" << std::endl;
    initialInput.get_user_keyboard_input(initialAccountCommand);
    if (std::stoi(initialAccountCommand) == 0) {
        uiAccountLogin();
    }
    if (std::stoi(initialAccountCommand) == 1) {
        uiAccountRegister();
    }
}
