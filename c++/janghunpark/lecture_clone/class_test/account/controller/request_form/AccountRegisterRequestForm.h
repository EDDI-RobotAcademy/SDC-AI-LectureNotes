//
// Created by eddi on 23. 12. 5.
//

#ifndef CLASS_TEST_ACCOUNTREGISTERREQUESTFORM_H
#define CLASS_TEST_ACCOUNTREGISTERREQUESTFORM_H


#include <string>
#include "../../service/request/AccountRegisterRequest.h"

class AccountRegisterRequestForm {
private:
    std::string account_id;
    std::string password;

public:
    AccountRegisterRequestForm(const std::string& account_id, const std::string& password);
    AccountRegisterRequest *toAccountRegisterRequest();
};


#endif //CLASS_TEST_ACCOUNTREGISTERREQUESTFORM_H
