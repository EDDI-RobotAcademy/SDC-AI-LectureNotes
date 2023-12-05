//
// Created by eddi on 23. 12. 5.
//

#ifndef CLASS_TEST_ACCOUNTREGISTERREQUEST_H
#define CLASS_TEST_ACCOUNTREGISTERREQUEST_H

#include <string>
#include "../../entity/Account.h"

class AccountRegisterRequest {
private:
    std::string account_id;
    std::string password;

public:
    AccountRegisterRequest(const std::string& account_id, const std::string& password);
    Account *toAccount();
    std::string getAccountId() const;
};


#endif //CLASS_TEST_ACCOUNTREGISTERREQUEST_H
