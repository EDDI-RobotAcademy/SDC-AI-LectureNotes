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
    bool insertData();
    bool updateData(int boardId, const std::string& newTitle, const std::string& newContent);
    bool deleteData(int boardId);
    void selectData();
    void readData(int boardId);

private:
    MYSQL* conn;
    const char* DB_HOST;
    const char* DB_USER;
    const char* DB_PASS;
    const char* DB_NAME;
};


#endif //CPP_TEST_DBPROCESS_H
