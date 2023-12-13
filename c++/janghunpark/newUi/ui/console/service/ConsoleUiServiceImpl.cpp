//
// Created by eddi on 23. 12. 4.
//

#include <string>
#include "ConsoleUiServiceImpl.h"
#include "../user_keyboard/user_keyboard_input.h"

ConsoleUiServiceImpl::ConsoleUiServiceImpl () { }

void ConsoleUiServiceImpl::makeAccountLoginRequestForm() {
    std::string input_account_id, input_password;
    user_keyboard_input forId, forPw;

    forId.get_user_keyboard_input_with_message("사용자 계정 id를 입력하세요: ", input_account_id);
    forPw.get_user_keyboard_input_with_message("사용자 계정 pw를 입력하세요: ", input_password);

//    return new *AccountLoginRequest(input_account_id, input_password);
}

int ConsoleUiServiceImpl::BoardReadRequestForm() {
    std::string readNoStrInfo;
    user_keyboard_input readNo;
    readNo.get_user_keyboard_input_with_message("조회할 게시물 번호를 입력하세요", readNoStrInfo);
    return std::stoi(readNoStrInfo);
}

