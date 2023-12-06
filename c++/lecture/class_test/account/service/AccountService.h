//
// Created by eddi on 23. 12. 5.
//

#ifndef CLASS_TEST_ACCOUNTSERVICE_H
#define CLASS_TEST_ACCOUNTSERVICE_H

#include <vector>
#include "response/AccountRegisterResponse.h"
#include "request/AccountRegisterRequest.h"
#include "response/AccountLoginResponse.h"
#include "request/AccountLoginRequest.h"

class AccountService {
public:
    virtual ~AccountService() = default;

    virtual AccountRegisterResponse *create(AccountRegisterRequest *request) = 0;
    virtual AccountLoginResponse *signIn(AccountLoginRequest *request) = 0;
    virtual void signOut(int sessionId) = 0;
    virtual std::string findAccoutIdBySessionId(int sessionId) = 0;
};

#endif //CLASS_TEST_ACCOUNTSERVICE_H
