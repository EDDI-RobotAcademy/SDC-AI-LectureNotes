//
// Created by eddi on 23. 12. 5.
//

#ifndef CLASS_TEST_ACCOUNTREPOSITORY_H
#define CLASS_TEST_ACCOUNTREPOSITORY_H

#include <vector>
#include "../entity/Account.h"

class AccountRepository {
public:
    virtual ~AccountRepository() = default;
    virtual Account *save(Account *acount) = 0;
    virtual bool findByAccountId(std::string account_id) = 0;
};

#endif //CLASS_TEST_ACCOUNTREPOSITORY_H
