//
// Created by eddi on 23. 12. 5.
//

#include "AccountRepositoryImpl.h"

AccountRepositoryImpl& AccountRepositoryImpl::getInstance()
{
    static AccountRepositoryImpl instance;
    return instance;
}

Account *AccountRepositoryImpl::save(Account *account)
{
    std::cout << "Account Repository save()" << std::endl;

    return account;
}