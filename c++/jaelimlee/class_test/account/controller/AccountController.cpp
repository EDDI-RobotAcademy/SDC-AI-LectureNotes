//
// Created by eddi on 23. 12. 5.
//

#include "AccountController.h"
#include "../service/AccountServiceImpl.h"
#include "../repository/AccountRepositoryImpl.h"

#include "request_form/AccountLoginRequestForm.h"
#include "request_form/AccountRegisterRequestForm.h"

#include "../service/request/AccountRegisterRequest.h"
#include "../service/request/AccountLoginRequest.h"

#include "response_form/AccountRegisterResponseForm.h"
#include "response_form/AccountLoginResponseForm.h"

#include "../service/response/AccountRegisterResponse.h"
#include "../service/response/AccountLoginResponse.h"


AccountController::AccountController(std::shared_ptr<AccountService> accountService) : accountService(accountService) { }

AccountRegisterResponseForm *
        AccountController::accountRegister(AccountRegisterRequestForm *requestForm)
{
    AccountRegisterResponse *response =
            accountService->create(requestForm->toAccountRegisterRequest());

    if (response == nullptr) { return nullptr; }

    return response->toResponseForm();
}

AccountLoginResponseForm *
AccountController::accountLogin(AccountLoginRequestForm *requestForm)
{
    AccountLoginResponse *response =
            accountService->signIn(requestForm->toAccountLoginRequest());

    if (response == nullptr) { return nullptr; }

    return response->toResponseForm();
}

void AccountController::accountLogout(int sessionId)
{
    accountService->signOut(sessionId);
}

AccountController& AccountController::getInstance(
        std::shared_ptr<AccountService> accountService)
{
    static AccountController instance(accountService);
    return instance;
}

AccountController& AccountController::getInstance() {
    static AccountController instance(
            std::make_shared<AccountServiceImpl>(
                    std::make_shared<AccountRepositoryImpl>()));

    return instance;
}
