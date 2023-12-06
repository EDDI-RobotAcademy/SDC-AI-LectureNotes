//
// Created by eddi on 23. 12. 5.
//

#include "Account.h"

Account::Account(const std::string& account_id, const std::string& password)
                        : account_id(account_id), password(password) { }

Account::Account(int id, const std::string& account_id, const std::string& password) : id(id),
                                                                                       account_id(account_id),
                                                                                       password(password),
                                                                                       reg_date(std::chrono::system_clock::now()),
                                                                                       upd_date(reg_date) { }

Account::Account(int id, const std::string& account_id, const std::string& password,
                 const std::string& reg_date, const std::string& upd_date) : id(id),
                                                                             account_id(account_id),
                                                                             password(password) { }

int Account::get_id()
{
    return id;
}

std::string Account::get_account_id() {
    return account_id;
}

std::string Account::get_password() {
    return password;
}

void Account::printAccountInfo() {

}