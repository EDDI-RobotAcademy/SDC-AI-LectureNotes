//
// Created by eddi on 23. 12. 5.
//

#ifndef CLASS_TEST_ACCOUNTREPOSITORYIMPL_H
#define CLASS_TEST_ACCOUNTREPOSITORYIMPL_H

#include "AccountRepository.h"

class AccountRepositoryImpl : public AccountRepository {

public:
    Account *save(Account *account) override;
    static AccountRepositoryImpl& getInstance();
};


#endif //CLASS_TEST_ACCOUNTREPOSITORYIMPL_H
