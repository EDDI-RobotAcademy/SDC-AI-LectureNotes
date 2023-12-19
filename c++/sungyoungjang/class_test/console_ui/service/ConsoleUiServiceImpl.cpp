//
// Created by eddi on 23. 12. 5.
//

#include "ConsoleUiServiceImpl.h"

#include <string>
#include "../../utility/keyboard/user_keyboard_input.h"

#include "../controller/ConsoleUiControllerCommand.h"
#include "../controller/ConsoleUiController.h"

ConsoleUiServiceImpl::ConsoleUiServiceImpl(std::shared_ptr<ConsoleUiRepository> consoleUiRepository)
                                                        : consoleUiRepository(consoleUiRepository) { }

AccountRegisterRequestForm *ConsoleUiServiceImpl::makeAccountRegisterForm()
{
    std::string input_account_id, input_password;

    get_user_keyboard_input_with_message("사용자 계정 id를 입력하세요: ", input_account_id);
    get_user_keyboard_input_with_message("사용자 계정 pw를 입력하세요: ", input_password);

    return new AccountRegisterRequestForm(input_account_id, input_password);
}

AccountLoginRequestForm *ConsoleUiServiceImpl::makeAccountLoginForm()
{
    std::string input_account_id, input_password;

    get_user_keyboard_input_with_message("id: ", input_account_id);
    get_user_keyboard_input_with_message("pw: ", input_password);

    return new AccountLoginRequestForm(input_account_id, input_password);
}

BoardRegisterRequestForm *ConsoleUiServiceImpl::makeBoardRegisterForm(int sessionId)
{
    std::string title, content;

    get_user_keyboard_input_with_message("게시물 제목을 입력하세요: ", title);
    get_user_keyboard_input_with_message("게시물 내용을 입력하세요: ", content);

    return new BoardRegisterRequestForm(title, sessionId, content);
}

BoardModifyRequestForm *ConsoleUiServiceImpl::makeBoardModifyForm(int boardNo)
{
    std::string title, content;

    get_user_keyboard_input_with_message("수정 할 게시물 제목을 입력하세요: ", title);
    get_user_keyboard_input_with_message("수정 할 게시물 내용을 입력하세요: ", content);

    return new BoardModifyRequestForm(boardNo, title, content);
}

void ConsoleUiServiceImpl::storeSession(int uniqueId)
{
    consoleUiRepository->storeSignInSession(uniqueId);
}

int ConsoleUiServiceImpl::getSignInSession()
{
    return consoleUiRepository->getSignInSession();
}

int ConsoleUiServiceImpl::makeBoardReadForm()
{
    std::string readNo;

    get_user_keyboard_input_with_message("읽을 게시물 번호를 입력하세요: ", readNo);

    return std::stoi(readNo);
}

void *ConsoleUiServiceImpl::determineParameter(int command)
{
    /*
    ACCOUNT_REGISTER,  = 0
    SIGN_IN,           = 1
    SIGN_OUT,          = 2
    BOARD_LIST,        = 3
    BOARD_REGISTER,    = 4
    BOARD_READ,        = 5
    BOARD_MODIFY,      = 6
    BOARD_REMOVE,      = 7
    UI_EXIT,           = 8
    */

    std::cout << "Command: " << command << std::endl;

    int* arr;

    switch (static_cast<ConsoleUiControllerCommand>(command)) {
        case ConsoleUiControllerCommand::BOARD_MODIFY:
        case ConsoleUiControllerCommand::BOARD_REMOVE:
            std::cout << "currentReadBoardNo: " << ConsoleUiController::getCurrentReadBoardNo() << std::endl;

            arr = new int;
            *arr = ConsoleUiController::getCurrentReadBoardNo();

            return static_cast<void*>(arr);

        case ConsoleUiControllerCommand::ACCOUNT_REGISTER:
        case ConsoleUiControllerCommand::SIGN_IN:
        case ConsoleUiControllerCommand::SIGN_OUT:
        case ConsoleUiControllerCommand::BOARD_LIST:
        case ConsoleUiControllerCommand::BOARD_REGISTER:
        case ConsoleUiControllerCommand::BOARD_READ:
        case ConsoleUiControllerCommand::UI_EXIT:
        case ConsoleUiControllerCommand::UI_COMMAND_END:
            return nullptr;
    }
}

ConsoleUiControllerCommand ConsoleUiServiceImpl::determineCommand(int sessionId, int command)
{
    /*
    if (getCurrentState() == ConsoleUiControllerCommand::BOARD_LIST) {
        std::cout << "1. 게시물 작성하기\n";
        std::cout << "2. 게시물 읽기\n";
        std::cout << "3. 종료\n";
        return;
    }

    if (getCurrentState() == ConsoleUiControllerCommand::BOARD_READ) {
        std::cout << "1. 게시물 수정하기\n";
        std::cout << "2. 게시물 삭제하기\n";
        std::cout << "3. 돌아가기\n";
        std::cout << "4. 종료\n";
        return;
    }

    if (sessionId == -1) {
        std::cout << "1. 회원가입\n";
        std::cout << "2. 로그인\n";
        std::cout << "3. 게시물 리스트 조회\n";
        std::cout << "4. 종료\n";
        return;
    }

    std::cout << "1. 로그아웃\n";
    std::cout << "2. 게시물 리스트 조회\n";
    std::cout << "3. 종료\n";
    */

    switch(command) {
        case 1:
            if (ConsoleUiController::getCurrentState() == ConsoleUiControllerCommand::BOARD_LIST) {
                return ConsoleUiControllerCommand::BOARD_REGISTER;
            }

            if (ConsoleUiController::getCurrentState() == ConsoleUiControllerCommand::BOARD_READ) {
                std::cout << "Modify" << std::endl;
                return ConsoleUiControllerCommand::BOARD_MODIFY;
            }

            if (sessionId == -1) { return ConsoleUiControllerCommand::ACCOUNT_REGISTER; }

            return ConsoleUiControllerCommand::SIGN_OUT;

        case 2:
            if (ConsoleUiController::getCurrentState() == ConsoleUiControllerCommand::BOARD_LIST) {
                return ConsoleUiControllerCommand::BOARD_READ;
            }

            if (ConsoleUiController::getCurrentState() == ConsoleUiControllerCommand::BOARD_READ) {
                return ConsoleUiControllerCommand::BOARD_REMOVE;
            }

            if (sessionId == -1) { return ConsoleUiControllerCommand::SIGN_IN; }

            return ConsoleUiControllerCommand::BOARD_LIST;

        case 3:
            if (ConsoleUiController::getCurrentState() == ConsoleUiControllerCommand::BOARD_READ) {
                return ConsoleUiControllerCommand::BOARD_LIST;
            }

            if (sessionId == -1) { return ConsoleUiControllerCommand::BOARD_LIST; }

            return ConsoleUiControllerCommand::UI_EXIT;

        case 4:
            return ConsoleUiControllerCommand::UI_EXIT;

        default:
            std::cout << "잘못 입력하셨습니다. 다시 입력하세요!" << std::endl;
    }
}