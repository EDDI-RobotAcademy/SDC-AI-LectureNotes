//
// Created by eddi on 23. 12. 5.
//

#include "ConsoleUiController.h"
#include "../../account/controller/AccountController.h"
#include "../service/ConsoleUiServiceImpl.h"
#include "../../account/controller/request_form/AccountLoginRequestForm.h"

ConsoleUiController::ConsoleUiController(
        std::shared_ptr<ConsoleUiService> consoleUiService)
            : consoleUiService(consoleUiService) { }

ConsoleUiController& ConsoleUiController::getInstance(
        std::shared_ptr<ConsoleUiService> consoleUiService)
{
    static ConsoleUiController instance(consoleUiService);
    return instance;
}

ConsoleUiController& ConsoleUiController::getInstance() {
    static ConsoleUiController instance(
            std::make_shared<ConsoleUiServiceImpl>());
    return instance;
}

void ConsoleUiController::uiAccountRegister()
{
    std::cout << "회원 가입을 진행합니다!" << std::endl;
    AccountRegisterRequestForm *requestForm;

    requestForm = consoleUiService->makeAccountRegisterForm();
    AccountController& accountController = AccountController::getInstance();

    AccountRegisterResponseForm *responseForm = accountController.accountRegister(requestForm);

    if (responseForm == nullptr) {
        std::cout << "중복된 계정입니다" << std::endl;
        // UI Command 창으로 보내야하지만 그냥 끝냄
        return;
    }

    if (responseForm->getIsRegisterSuccess()) {
        uiAccountLogin();
    }
}

void ConsoleUiController::uiAccountLogin()
{
    std::cout << "로그인 콘솔 창입니다." << std::endl;
    AccountLoginRequestForm *requestForm;

    requestForm = consoleUiService->makeAccountLoginForm();
    AccountController& accountController = AccountController::getInstance();

    //accountController.accountLogin(requestForm);
}