//
// Created by eddi on 23. 12. 5.
//

#ifndef CLASS_TEST_ACCOUNTREPOSITORYIMPL_H
#define CLASS_TEST_ACCOUNTREPOSITORYIMPL_H

#include "AccountRepository.h"
#include <optional>

class AccountRepositoryImpl : public AccountRepository {

public:
    Account *save(Account *account) override;
    bool getBoolWithFindByAccountId(std::string account_id) override;
    std::optional<Account> findByAccountId(std::string accountId) override;
    void deleteSession(int sessionId) override;
    std::optional<Account> findAccountIdBySessionId(int sessionId) override;

    static AccountRepositoryImpl& getInstance();
};


#endif //CLASS_TEST_ACCOUNTREPOSITORYIMPL_H
