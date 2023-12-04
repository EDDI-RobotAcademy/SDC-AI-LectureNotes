//
// Created by eddi on 23. 11. 29.
//

#ifndef CPP_TEST_DBPROCESS_H
#define CPP_TEST_DBPROCESS_H

#include <mysql/mysql.h>
#include <string>

class DbProcess {
public:
    DbProcess(const char* host, const char* user, const char* pass, const char* dbName);
    ~DbProcess();

    bool connect();
    bool insertDataBoard();
    bool insertDataAccount();
    bool updateDataBoard(int boardId, const std::string& newTitle, const std::string& newContent);
    bool updateDataAccount(int uid, const std::string& newName, const std::string& newPassword);
    bool deleteBoardData(int boardId);
    bool deleteAccountData(int uid);
    void selectBoardData();
    void selectAccountData();
    void readBoardData(int boardId);
    void readAccountData(int uid);

private:
    MYSQL* conn;
    const char* DB_HOST;
    const char* DB_USER;
    const char* DB_PASS;
    const char* DB_NAME;
};


#endif //CPP_TEST_DBPROCESS_H
