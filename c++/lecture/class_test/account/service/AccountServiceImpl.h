//
// Created by eddi on 23. 12. 5.
//

#ifndef CLASS_TEST_ACCOUNTSERVICEIMPL_H
#define CLASS_TEST_ACCOUNTSERVICEIMPL_H

#include <vector>
#include <memory>
#include "response/AccountRegisterResponse.h"
#include "../repository/AccountRepository.h"
#include "AccountService.h"
#include "request/AccountRegisterRequest.h"

class AccountServiceImpl : public AccountService {
private:
    std::shared_ptr<AccountRepository> accountRepository;

public:
    AccountServiceImpl(std::shared_ptr<AccountRepository> accountRepository);
    AccountRegisterResponse *create(AccountRegisterRequest *request) override;
    static AccountServiceImpl& getInstance(std::shared_ptr<AccountRepository> accountRepository);
};


#endif //CLASS_TEST_ACCOUNTSERVICEIMPL_H
