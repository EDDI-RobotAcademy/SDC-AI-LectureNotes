//
// Created by eddi on 23. 12. 5.
//

#ifndef CLASS_TEST_ACCOUNTSERVICE_H
#define CLASS_TEST_ACCOUNTSERVICE_H

#include <vector>
#include "response/AccountRegisterResponse.h"
#include "request/AccountRegisterRequest.h"

class AccountService {
public:
    virtual ~AccountService() = default;

    virtual AccountRegisterResponse *create(AccountRegisterRequest *pRequest) = 0;
};

#endif //CLASS_TEST_ACCOUNTSERVICE_H
