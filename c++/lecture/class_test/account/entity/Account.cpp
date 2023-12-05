//
// Created by eddi on 23. 12. 5.
//

#include "Account.h"

Account::Account(int id, const std::string& account_id, const std::string& password) : id(id),
                                                                                       account_id(account_id),
                                                                                       password(password),
                                                                                       reg_date(std::chrono::system_clock::now()),
                                                                                       upd_date(reg_date) { }

Account::Account(int id, const std::string& account_id, const std::string& password,
                 const std::string& reg_date, const std::string& upd_date) : id(id),
                                                                             account_id(account_id),
                                                                             password(password) { }

void Account::printAccountInfo() {

}