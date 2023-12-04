//
// Created by eddi on 23. 12. 4.
//

#ifndef CPP_TEST_DBPROCESSBOARD_H
#define CPP_TEST_DBPROCESSBOARD_H


#include <mysql.h>

class DbProcessBoard {
private:
    bool connect();
    bool insertDataBoard();
    bool updateDataBoard(int boardId, const std::string& newTitle, const std::string& newContent);
    bool deleteBoardData(int boardId);
    void selectBoardData();
    void readBoardData(int boardId);
    ~DbProcessBoard();

public:
    MYSQL* conn;
    const char* DB_HOST;
    const char* DB_USER;
    const char* DB_PASS;
    const char* DB_NAME;

};


#endif //CPP_TEST_DBPROCESSBOARD_H
