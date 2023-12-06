//
// Created by eddi on 23. 12. 6.
//

#ifndef CLASS_TEST_ACCOUNTLOGINRESPONSE_H
#define CLASS_TEST_ACCOUNTLOGINRESPONSE_H

#include "../../controller/response_form/AccountLoginResponseForm.h"

class AccountLoginResponse {
private:
    int login_account_unique_id;

public:
    AccountLoginResponse (int id);
    AccountLoginResponseForm *toResponseForm();
};


#endif //CLASS_TEST_ACCOUNTLOGINRESPONSE_H
