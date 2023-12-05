//
// Created by eddi on 23. 12. 5.
//

#ifndef CLASS_TEST_CONSOLEUISERVICE_H
#define CLASS_TEST_CONSOLEUISERVICE_H

#include "../../account/controller/request_form/AccountRegisterRequestForm.h"

class ConsoleUiService {
public:
    virtual ~ConsoleUiService() = default;

    virtual AccountRegisterRequestForm *makeAccountRegisterForm() = 0;
};

#endif //CLASS_TEST_CONSOLEUISERVICE_H
