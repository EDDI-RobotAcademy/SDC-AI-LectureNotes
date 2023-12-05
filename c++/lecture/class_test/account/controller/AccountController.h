//
// Created by eddi on 23. 12. 5.
//

#ifndef CLASS_TEST_ACCOUNTCONTROLLER_H
#define CLASS_TEST_ACCOUNTCONTROLLER_H

#include <memory>
#include <vector>
#include "../service/AccountService.h"
#include "response_form/AccountRegisterResponseForm.h"
#include "request_form/AccountRegisterRequestForm.h"

class AccountController {
private:
    std::shared_ptr<AccountService> accountService;

public:
    AccountController(std::shared_ptr<AccountService> accountService);

    AccountRegisterResponseForm *accountRegister(AccountRegisterRequestForm *pForm);
    static AccountController& getInstance(std::shared_ptr<AccountService> accountService);
    static AccountController& getInstance();
};


#endif //CLASS_TEST_ACCOUNTCONTROLLER_H
