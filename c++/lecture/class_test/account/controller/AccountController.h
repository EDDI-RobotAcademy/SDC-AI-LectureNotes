//
// Created by eddi on 23. 12. 5.
//

#ifndef CLASS_TEST_ACCOUNTCONTROLLER_H
#define CLASS_TEST_ACCOUNTCONTROLLER_H

#include <memory>
#include <vector>
#include "../service/AccountService.h"
#include "response_form/AccountRegisterResponseForm.h"

class AccountController {
private:
    std::shared_ptr<AccountService> accountService;

public:
    AccountController(std::shared_ptr<AccountService> accountService);

    std::vector<AccountRegisterResponseForm> accountRegister();
};


#endif //CLASS_TEST_ACCOUNTCONTROLLER_H
