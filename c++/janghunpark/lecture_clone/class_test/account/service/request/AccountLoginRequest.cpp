//
// Created by oem on 23. 12. 5.
//

#include "AccountLoginRequest.h"

AccountLoginRequest::AccountLoginRequest(
        const std::string& account_id, const std::string& password) :
        account_id(account_id), password(password) { }

Account *AccountLoginRequest::toAccount()
{
    return new Account(account_id, password);
}

std::string AccountLoginRequest::getAccountId() const {
    return account_id;
}

std::string AccountLoginRequest::getPassword() const {
    return password;
}