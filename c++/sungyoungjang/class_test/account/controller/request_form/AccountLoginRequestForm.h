//
// Created by oem on 23. 12. 5.
//

#ifndef CLASS_TEST_ACCOUNTLOGINREQUESTFORM_H
#define CLASS_TEST_ACCOUNTLOGINREQUESTFORM_H

#include <string>
#include "../../service/request/AccountLoginRequest.h"

class AccountLoginRequestForm {
private:
    std::string account_id;
    std::string password;

public:
    AccountLoginRequestForm(const std::string& account_id, const std::string& password);
    AccountLoginRequest *toAccountLoginRequest();
};


#endif //CLASS_TEST_ACCOUNTLOGINREQUESTFORM_H
