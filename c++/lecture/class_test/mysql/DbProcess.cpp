//
// Created by eddi on 23. 11. 29.
//

#include "DbProcess.h"
#include "../board/entity/Board.h"
#include <iostream>
#include <optional>
#include <tuple>
#include <vector>
#include <any>

DbProcess* DbProcess::instance = nullptr;

DbProcess::DbProcess(const char* host, const char* user, const char* pass, const char* dbName)
        : conn(nullptr), DB_HOST(host), DB_USER(user), DB_PASS(pass), DB_NAME(dbName) {}

DbProcess::~DbProcess() {
    if (conn != nullptr) {
        mysql_close(conn);
    }
}

DbProcess* DbProcess::getInstance(const char* host, const char* user, const char* pass, const char* dbName) {
    if (instance == nullptr) {
        instance = new DbProcess(host, user, pass, dbName);
    }
    return instance;
}

DbProcess* DbProcess::getInstance() {
    return instance;
}

bool DbProcess::connect() {
    conn = mysql_init(nullptr);
    return (mysql_real_connect(conn, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3306, nullptr, 0) != nullptr);
}

bool DbProcess::insertData(const std::string& queryString) {
    return (mysql_query(conn, queryString.c_str()) == 0);
}

bool DbProcess::updateData(int boardId, const std::string& newTitle, const std::string& newContent) {
    std::string updateQuery = "UPDATE board SET title = '" + newTitle +
                              "', content = '" + newContent +
                              "' WHERE board_id = " + std::to_string(boardId);

    return (mysql_query(conn, updateQuery.c_str()) == 0);
}

//bool DbProcess::deleteData(int boardId) {
//    std::string deleteQuery = "DELETE FROM board WHERE board_id = " + std::to_string(boardId);
//
//    return (mysql_query(conn, deleteQuery.c_str()) == 0);
//}
bool DbProcess::deleteData(const std::string& queryString) {
    return (mysql_query(conn, queryString.c_str()) == 0);
}

void DbProcess::selectData() {
    std::string selectQuery = "SELECT * FROM board";

    if (mysql_query(conn, selectQuery.c_str()) == 0) {
        MYSQL_RES* result = mysql_store_result(conn);
        if (result == nullptr) {
            std::cerr << "mysql_store_result() failed" << std::endl;
            return;
        }

        MYSQL_ROW row;
        while ((row = mysql_fetch_row(result)) != nullptr) {
            std::cout << "board_id: " << row[0] << ", content: " << row[1]
                      << ", reg_date: " << (row[2] ? row[2] : "NULL") << ", title: " << row[3]
                      << ", upd_date: " << (row[4] ? row[4] : "NULL") << ", writer: " << row[5] << std::endl;
        }

        mysql_free_result(result);
    } else {
        std::cerr << "mysql_query() failed" << std::endl;
    }
}

void DbProcess::readData(int boardId) {
    std::string readQuery = "SELECT * FROM board WHERE board_id = " + std::to_string(boardId);
    if (mysql_query(conn, readQuery.c_str()) == 0) {
        MYSQL_RES* result = mysql_store_result(conn);
        if (result == nullptr) {
            std::cerr << "mysql_store_result() failed" << std::endl;
            return;
        }

        MYSQL_ROW row = mysql_fetch_row(result);
        if (row != nullptr) {
            std::cout << "board_id: " << row[0] << ", content: " << row[1]
                      << ", reg_date: " << (row[2] ? row[2] : "NULL") << ", title: " << row[3]
                      << ", upd_date: " << (row[4] ? row[4] : "NULL") << ", writer: " << row[5] << std::endl;
        } else {
            std::cout << "Record not found for board_id: " << boardId << std::endl;
        }

        mysql_free_result(result);
    } else {
        std::cerr << "mysql_query() failed" << std::endl;
    }
}

bool DbProcess::findData(const std::string& queryString) {
    if (mysql_query(conn, queryString.c_str()) == 0) {
        MYSQL_RES* result = mysql_store_result(conn);
        if (result == nullptr) {
            std::cerr << "mysql_store_result() failed" << std::endl;
            return false;
        }

        MYSQL_ROW row = mysql_fetch_row(result);

        if (row != nullptr) {
            mysql_free_result(result);
            return true;
        } else {
            mysql_free_result(result);
            return false;
        }
    } else {
        std::cerr << "mysql_query() failed" << std::endl;
        return false;
    }
}

MYSQL_ROW DbProcess::findRowData(const std::string& queryString) {
    if (mysql_query(conn, queryString.c_str()) == 0) {
        MYSQL_RES* result = mysql_store_result(conn);
        if (result == nullptr) {
            std::cerr << "mysql_store_result() failed" << std::endl;
            return nullptr;
        }

        MYSQL_ROW row = mysql_fetch_row(result);
        mysql_free_result(result);
        return row;
    } else {
        std::cerr << "mysql_query() failed" << std::endl;
        return nullptr;
    }
}

MYSQL *DbProcess::getConn()
{
    return conn;
}

template <typename T>
T *DbProcess::insertOldEntityData(const std::string& queryString) {
    if (mysql_query(conn, queryString.c_str()) == 0) {
        MYSQL_RES* result = mysql_store_result(conn);
        if (result) {
            MYSQL_ROW row = mysql_fetch_row(result);
            if (row) {
                T* insertedEntity = new T;
                std::apply([&row, insertedEntity](auto&&... args) {
                    *insertedEntity = T(std::stoi(row[args])...);
                }, insertedEntity->getAttributes());

                mysql_free_result(result);
                return insertedEntity;
            }
            mysql_free_result(result);
        }
    }

    throw std::runtime_error("데이터 입력 중 오류가 발생하였습니다.");
}

//template <typename T>
//std::unique_ptr<T> DbProcess::insertEntityData(const std::string& queryString) {
//    if (mysql_query(conn, queryString.c_str()) == 0) {
//        MYSQL_RES* result = mysql_store_result(conn);
//        if (result) {
//            MYSQL_ROW row = mysql_fetch_row(result);
//            if (row) {
//                T insertedEntity;
//                std::apply([&row, &insertedEntity](auto&&... args) {
//                    (insertedEntity.initializeFromRow(std::stoi(row[args])), ...);
//                }, T::getAttributes());
//
//                mysql_free_result(result);
//                return std::make_unique<T>(insertedEntity);
//            }
//            mysql_free_result(result);
//        }
//    }
//
//    throw std::runtime_error("데이터 입력 중 오류가 발생하였습니다.");
//}

template <typename T>
std::unique_ptr<T> DbProcess::insertEntityData(const std::string& queryString) {
    if (mysql_query(conn, queryString.c_str()) == 0) {
        MYSQL_RES* result = mysql_store_result(conn);
        if (result) {
            MYSQL_ROW row = mysql_fetch_row(result);
            if (row) {
                std::unique_ptr<T> insertedEntity = std::make_unique<T>();

                auto attributes = T::getAttributes();
                constexpr size_t attributeCount = std::tuple_size_v<decltype(attributes)>;

                insertedEntity->initializeFromRow(std::stoi(row[0]), row[1], row[2], row[3], row[4], row[5]);

                mysql_free_result(result);
                return insertedEntity;
            }
            mysql_free_result(result);
        }
    }

    throw std::runtime_error("DB에 데이터를 넣는 중 문제가 발생하였습니다.");
}

template std::unique_ptr<Board> DbProcess::insertEntityData(const std::string& queryString);

std::vector<std::string> fetchRow(MYSQL_RES* result) {
    MYSQL_ROW row = mysql_fetch_row(result);
    if (!row) {
        throw std::runtime_error("Failed to fetch row");
    }

    unsigned int numFields = mysql_num_fields(result);
    std::vector<std::string> values(numFields);

    for (unsigned int i = 0; i < numFields; ++i) {
        values[i] = row[i];
    }

    return values;
}

template <typename T>
std::unique_ptr<T> DbProcess::insertDataAfterReturnEntity(const std::string& queryString) {
    if (mysql_query(conn, queryString.c_str()) == 0) {
        MYSQL_RES* result = mysql_store_result(conn);
        if (result) {
            std::vector<std::string> rowValues = fetchRow(result);

            std::unique_ptr<T> insertedEntity = std::make_unique<T>();
            insertedEntity->initializeFromRow(rowValues);

            mysql_free_result(result);
            return insertedEntity;
        }
    }

    throw std::runtime_error("DB에 데이터를 넣는 중 문제가 발생하였습니다.");
}

template std::unique_ptr<Board> DbProcess::insertDataAfterReturnEntity(const std::string& queryString);