//
// Created by eddi on 23. 12. 5.
//

#ifndef CLASS_TEST_ACCOUNTSERVICEIMPL_H
#define CLASS_TEST_ACCOUNTSERVICEIMPL_H

#include <vector>
#include <memory>

#include "request/AccountRegisterRequest.h"
#include "request/AccountLoginRequest.h"

#include "response/AccountRegisterResponse.h"
#include "response/AccountLoginResponse.h"

#include "../repository/AccountRepository.h"
#include "AccountService.h"


class AccountServiceImpl : public AccountService {
private:
    std::shared_ptr<AccountRepository> accountRepository;

public:
    AccountServiceImpl(std::shared_ptr<AccountRepository> accountRepository);

    AccountRegisterResponse *create(AccountRegisterRequest *request) override;
    AccountLoginResponse *signIn(AccountLoginRequest *request) override;
    void signOut(int sessionId) override;

    static AccountServiceImpl& getInstance(std::shared_ptr<AccountRepository> accountRepository);
};


#endif //CLASS_TEST_ACCOUNTSERVICEIMPL_H
