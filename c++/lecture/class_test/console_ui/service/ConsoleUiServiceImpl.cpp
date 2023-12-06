//
// Created by eddi on 23. 12. 5.
//

#include "ConsoleUiServiceImpl.h"

#include <string>
#include "../../utility/keyboard/user_keyboard_input.h"

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

void ConsoleUiServiceImpl::storeSession(int uniqueId)
{
    consoleUiRepository->storeSignInSession(uniqueId);
}

int ConsoleUiServiceImpl::getSignInSession()
{
    return consoleUiRepository->getSignInSession();
}