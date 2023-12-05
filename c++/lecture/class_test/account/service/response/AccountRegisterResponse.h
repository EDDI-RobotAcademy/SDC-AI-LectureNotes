//
// Created by eddi on 23. 12. 5.
//

#ifndef CLASS_TEST_ACCOUNTREGISTERRESPONSE_H
#define CLASS_TEST_ACCOUNTREGISTERRESPONSE_H


#include "../../controller/response_form/AccountRegisterResponseForm.h"

class AccountRegisterResponse {
private:
    int login_account_unique_id;

public:
    AccountRegisterResponse (int id);
    AccountRegisterResponseForm *toResponseForm();
};


#endif //CLASS_TEST_ACCOUNTREGISTERRESPONSE_H
