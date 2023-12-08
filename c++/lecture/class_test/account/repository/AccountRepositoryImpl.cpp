//
// Created by eddi on 23. 12. 5.
//

#include "AccountRepositoryImpl.h"
#include "../../mysql/DbProcess.h"

std::shared_ptr<AccountRepositoryImpl> AccountRepositoryImpl::instance;

AccountRepositoryImpl::AccountRepositoryImpl() {
    std::cout << "AccountRepositoryImpl instance created!" << std::endl;
}

std::shared_ptr<AccountRepositoryImpl> AccountRepositoryImpl::getInstance()
{
    if (!instance) {
        std::cout << "Creating new AccountRepositoryImpl instance" << std::endl;

        instance = std::make_shared<AccountRepositoryImpl>();

    }

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

bool AccountRepositoryImpl::getBoolWithFindByAccountId(std::string account_id)
{
    DbProcess* dbInstance = DbProcess::getInstance();
    std::string queryString = "SELECT * FROM account WHERE account_id = '" + account_id + "'";

    return dbInstance->findData(queryString);
}

#include <mysql/mysql.h>
#include <iostream>
#include <chrono>
#include <sstream>
#include <iomanip>

#include "../entity/Account.h"

std::chrono::system_clock::time_point convertStringToTimePoint(const std::string& str) {
    std::tm tm = {};
    std::istringstream ss(str);
    ss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");

    if (ss.fail()) {
        throw std::runtime_error("Error parsing date string");
    }

    std::time_t time = std::mktime(&tm);
    if (time == -1) {
        throw std::runtime_error("Error converting time");
    }

    return std::chrono::system_clock::from_time_t(time);
}

Account constructAccountFromRow(MYSQL_ROW row) {
    int id = std::stoi(row[0]);
    std::string account_id = row[1];
    std::string password = row[2];

    std::string reg_date_str = row[3];
    std::string upd_date_str = row[4];

    std::chrono::system_clock::time_point reg_date = convertStringToTimePoint(reg_date_str);
    std::chrono::system_clock::time_point upd_date = convertStringToTimePoint(upd_date_str);

    if (!reg_date_str.empty() && !upd_date_str.empty()) {
        return Account(id, account_id, password, reg_date_str, upd_date_str);
    } else {
        return Account(id, account_id, password);
    }
}

std::optional<Account> AccountRepositoryImpl::findByAccountId(std::string accountId)
{
    DbProcess* dbInstance = DbProcess::getInstance();
    std::string queryString = "SELECT * FROM account WHERE account_id = '" + accountId + "'";

    MYSQL_ROW row = dbInstance->findRowData(queryString);

    if (row != nullptr) {
        Account acc = constructAccountFromRow(row);
        return std::make_optional(acc);
    } else {
        return std::nullopt;
    }
}

void AccountRepositoryImpl::deleteSession(int sessionId)
{
    DbProcess* dbInstance = DbProcess::getInstance();

    std::string deleteQuery = "DELETE FROM session WHERE session_id = " + std::to_string(sessionId);

    dbInstance->deleteData(deleteQuery);
}

std::optional<Account> AccountRepositoryImpl::findAccountIdBySessionId(int sessionId)
{
    DbProcess* dbInstance = DbProcess::getInstance();
    std::string queryString = "SELECT * FROM account WHERE id = '" + std::to_string(sessionId) + "'";

    MYSQL_ROW row = dbInstance->findRowData(queryString);

    if (row != nullptr) {
        Account acc = constructAccountFromRow(row);
        return std::make_optional(acc);
    } else {
        return std::nullopt;
    }
}