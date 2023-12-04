//
// Created by eddi on 23. 12. 4.
//

#ifndef CPP_TEST_DBPROCESSACCOUNT_H
#define CPP_TEST_DBPROCESSACCOUNT_H


#include <mysql.h>

class DbProcessAccount {
private:
    DbProcessAccount(const char* host, const char* user, const char* pass, const char* dbName);
    bool connect();
    bool insertDataAccount();
    bool updateDataAccount(int uid, const std::string& newName, const std::string& newPassword);
    bool deleteAccountData(int uid);
    void selectAccountData();
    void readAccountData(int uid);
    ~DbProcessAccount();
public:
    MYSQL* conn;
    const char* DB_HOST;
    const char* DB_USER;
    const char* DB_PASS;
    const char* DB_NAME;
};


#endif //CPP_TEST_DBPROCESSACCOUNT_H
