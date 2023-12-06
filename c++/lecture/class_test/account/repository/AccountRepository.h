//
// Created by eddi on 23. 12. 5.
//

#ifndef CLASS_TEST_ACCOUNTREPOSITORY_H
#define CLASS_TEST_ACCOUNTREPOSITORY_H

#include <vector>
#include <optional>
#include "../entity/Account.h"

class AccountRepository {
public:
    virtual ~AccountRepository() = default;
    virtual Account *save(Account *acount) = 0;
    virtual bool getBoolWithFindByAccountId(std::string account_id) = 0;
    virtual std::optional<Account> findByAccountId(std::string accountId) = 0;
    virtual void deleteSession(int sessionId) = 0;
    virtual std::optional<Account> findAccountIdBySessionId(int sessionId) = 0;
};

#endif //CLASS_TEST_ACCOUNTREPOSITORY_H
