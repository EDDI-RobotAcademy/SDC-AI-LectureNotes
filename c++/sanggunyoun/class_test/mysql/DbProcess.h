//
// Created by eddi on 23. 11. 29.
//

#ifndef CPP_TEST_DBPROCESS_H
#define CPP_TEST_DBPROCESS_H

#include <mysql/mysql.h>
#include <string>
#include <optional>
#include <memory>

class DbProcess {
public:
    DbProcess(const char* host, const char* user, const char* pass, const char* dbName);
    ~DbProcess();

    static DbProcess* getInstance(const char* host, const char* user, const char* pass, const char* dbName);
    static DbProcess* getInstance();

    bool connect();
    bool insertData(const std::string& queryString);

    template <typename T>
    T *insertOldEntityData(const std::string& queryString);
    template <typename T>
    std::unique_ptr<T> insertEntityData(const std::string& queryString);

    template <typename T>
    std::unique_ptr<T> insertDataAfterReturnEntity(const std::string& queryString);

    bool updateData(int boardId, const std::string& newTitle, const std::string& newContent);
    //bool deleteData(int boardId);
    bool deleteData(const std::string& queryString);
    void selectData();
    void readData(int boardId);
    bool findData(const std::string& queryString);
    MYSQL_ROW findRowData(const std::string& queryString);

    MYSQL *getConn();

private:
    static DbProcess* instance;

    MYSQL* conn;
    const char* DB_HOST;
    const char* DB_USER;
    const char* DB_PASS;
    const char* DB_NAME;
};


#endif //CPP_TEST_DBPROCESS_H
