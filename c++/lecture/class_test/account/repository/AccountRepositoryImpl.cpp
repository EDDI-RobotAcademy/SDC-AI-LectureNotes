//
// Created by eddi on 23. 12. 5.
//

#include "AccountRepositoryImpl.h"
#include "../../mysql/DbProcess.h"

AccountRepositoryImpl& AccountRepositoryImpl::getInstance()
{
    static AccountRepositoryImpl instance;
    return instance;
}

Account *AccountRepositoryImpl::save(Account *account)
{
    DbProcess* dbInstance = DbProcess::getInstance();
    std::string accountId = account->get_account_id();
    std::string password = account->get_password();

    std::string queryString = "INSERT INTO account (account_id, password) VALUES \
                          ('" + accountId + "', '" + password + "' )";

    dbInstance->insertData(queryString);

    return account;
}

bool AccountRepositoryImpl::findByAccountId(std::string account_id)
{
    DbProcess* dbInstance = DbProcess::getInstance();
    std::string queryString = "SELECT * FROM account WHERE account_id = '" + account_id + "'";

    return dbInstance->findData(queryString);
}