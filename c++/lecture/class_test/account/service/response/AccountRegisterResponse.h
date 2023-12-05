//
// Created by eddi on 23. 12. 5.
//

#ifndef CLASS_TEST_ACCOUNTREGISTERRESPONSE_H
#define CLASS_TEST_ACCOUNTREGISTERRESPONSE_H


#include "../../controller/response_form/AccountRegisterResponseForm.h"

class AccountRegisterResponse {
private:
    bool is_register_success;

public:
    AccountRegisterResponse (bool is_register_success);
    AccountRegisterResponseForm *toResponseForm();
};


#endif //CLASS_TEST_ACCOUNTREGISTERRESPONSE_H
