//
// Created by eddi on 23. 12. 5.
//

#ifndef CLASS_TEST_CONSOLEUISERVICEIMPL_H
#define CLASS_TEST_CONSOLEUISERVICEIMPL_H

#include "ConsoleUiService.h"
#include "../../account/controller/request_form/AccountRegisterRequestForm.h"
#include "../../account/controller/request_form/AccountLoginRequestForm.h"

class ConsoleUiServiceImpl : public ConsoleUiService {

public:
    static ConsoleUiServiceImpl& getInstance();
    AccountRegisterRequestForm *makeAccountRegisterForm() override;
    AccountLoginRequestForm *makeAccountLoginForm() override;
};


#endif //CLASS_TEST_CONSOLEUISERVICEIMPL_H
