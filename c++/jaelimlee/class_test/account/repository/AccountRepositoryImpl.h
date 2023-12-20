//
// Created by eddi on 23. 12. 5.
//

#ifndef CLASS_TEST_ACCOUNTREPOSITORYIMPL_H
#define CLASS_TEST_ACCOUNTREPOSITORYIMPL_H

#include "AccountRepository.h"
#include <optional>
#include <memory>

class AccountRepositoryImpl : public AccountRepository {
private:
    static std::shared_ptr<AccountRepositoryImpl> instance;

public:
    Account *save(Account *account) override;
    bool getBoolWithFindByAccountId(std::string account_id) override;
    std::optional<Account> findByAccountId(std::string accountId) override;
    void deleteSession(int sessionId) override;
    std::optional<Account> findAccountIdBySessionId(int sessionId) override;

    AccountRepositoryImpl();

    static std::shared_ptr<AccountRepositoryImpl> getInstance();
};


#endif //CLASS_TEST_ACCOUNTREPOSITORYIMPL_H
