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
#include "../repository/AccountRepositoryImpl.h"


class AccountServiceImpl : public AccountService {
private:
    static std::shared_ptr<AccountServiceImpl> instance;
    std::shared_ptr<AccountRepositoryImpl> accountRepository;

public:
    AccountServiceImpl(std::shared_ptr<AccountRepositoryImpl> accountRepository);

    AccountRegisterResponse *create(AccountRegisterRequest *request) override;
    AccountLoginResponse *signIn(AccountLoginRequest *request) override;
    void signOut(int sessionId) override;
    std::string findAccoutIdBySessionId(int sessionId) override;

    static std::shared_ptr<AccountServiceImpl> getInstance(std::shared_ptr<AccountRepositoryImpl> accountRepository);
    static std::shared_ptr<AccountServiceImpl> getInstance();
};


#endif //CLASS_TEST_ACCOUNTSERVICEIMPL_H
