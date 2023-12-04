//
// Created by eddi on 23. 12. 4.
//

#include <string>
#include <iostream>
#include "DbProcessAccount.h"


DbProcessAccount::DbProcessAccount(const char* host, const char* user, const char* pass, const char* dbName)
        : conn(nullptr), DB_HOST(host), DB_USER(user), DB_PASS(pass), DB_NAME(dbName) {}

DbProcessAccount::~DbProcessAccount() {
    if (conn != nullptr) {
        mysql_close(conn);
    }
}
bool DbProcessAccount::connect() {
    // mysql_init()을 통해 mysql에 접속하기 위한 객체를 만듬
    // 그 객체는 conn에 배치됨
    // 그리고 mysql_real_connect()룰 호출하여
    // 생성자에서 맵핑해놓은 값을 입력하여 DB에 연결합니다.
    // 계정, 비밀번호, 사용할 데이터베이스, localhost(내 컴퓨터)
    conn = mysql_init(nullptr);
    return (mysql_real_connect(conn, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3306, nullptr, 0) != nullptr);
}

bool DbProcessAccount::insertDataAccount() {
    // 사실상 char * 와 같은 것임
    std::string insertQuery = "INSERT INTO Account (uid, name, password, reg_date, upd_date) VALUES \
                               ('uid', '계정명', '비밀번호', now(6), now(6))";

    // DB query를 mysql_query를 통해 날림
    // 앞서 만든 mysql 통신 객체인 conn과 위의 DB query 문자열을 전달
    // DB query 문자열을 전달하기 위해 insertQuery.c_str() 형태로 전달
    return (mysql_query(conn, insertQuery.c_str()) == 0);
}

bool DbProcessAccount::updateDataAccount(int uid, const std::string& newName, const std::string& newPassword) {
    std::string updateQuery = "UPDATE account SET name = '" + newName +
                              "', content = '" + newPassword +
                              "' WHERE uid = " + std::to_string(uid);

    return (mysql_query(conn, updateQuery.c_str()) == 0);
}

bool DbProcessAccount::deleteAccountData(int uid) {
    std::string deleteQuery = "DELETE FROM account WHERE uid = " + std::to_string(uid);

    return (mysql_query(conn, deleteQuery.c_str()) == 0);
}
void DbProcessAccount::selectAccountData() {
    // select * from board; 명령을 입력하면 전체 데이터를 볼 수 있음
    std::string selectQuery = "SELECT * FROM account";
    // mysql_query는 쉽게 생각하면 request라고 보면 됨
    // request 하는 정보는 위의 문자열에 해당함
    if (mysql_query(conn, selectQuery.c_str()) == 0) {
        // 위에서 처리한 select 결과를 result에 저장
        MYSQL_RES* result = mysql_store_result(conn);
        if (result == nullptr) {
            std::cerr << "mysql_store_result() failed" << std::endl;
            return;
        }

        // 결과 값의 행 값들을 하나씩 분리하면서 분석
        // 실제 select * from board; 를 입력 했을 때
        // 나타나는 행의 개수가 몇 개인지 모름
        // 그러므로 while을 통해 result에서 row가 없을 때까지 루프를 돌면서
        // 내부에 있는 행 값들을 출력하는 작업을 수행합니다.
        MYSQL_ROW row;
        while ((row = mysql_fetch_row(result)) != nullptr) {
            std::cout << "uid: " << row[0] << ", name: " << row[1]
                      << ", reg_date: " << (row[2] ? row[2] : "NULL") << ", password: " << row[3]
                      << ", upd_date: " << (row[4] ? row[4] : "NULL") << ", NULL: " << row[5] << std::endl;
        }

        // 문자열을 처리 했기 때문에 메모리 할당을 한 것인데
        // 이에 대한 메모리 정리 작업을 진행합니다.
        mysql_free_result(result);
    } else {
        std::cerr << "mysql_query() failed" << std::endl;
    }
}

void DbProcessAccount::readAccountData(int uid) {
    // 읽기의 경우도 사실은 select 기반
    // 다만 조건을 where로 줍니다.
    // where board_id가 몇이냐를 기준으로 합니다.
    // 우리가 직접 만들었던 부분에서 이 녀석은 결국 unique id 입니다.

    // readData(int boardId, char *tableName)
    // fprintf(buff, "select * from %s where board_id = 3", length);
    // mysql_query(conn, buff)
    std::string readQuery = "SELECT * FROM account WHERE uid = " + std::to_string(uid);
    if (mysql_query(conn, readQuery.c_str()) == 0) {
        MYSQL_RES* result = mysql_store_result(conn);
        if (result == nullptr) {
            std::cerr << "mysql_store_result() failed" << std::endl;
            return;
        }

        MYSQL_ROW row = mysql_fetch_row(result);
        if (row != nullptr) {
            std::cout << "uid: " << row[0] << ", name: " << row[1]
                      << ", reg_date: " << (row[2] ? row[2] : "NULL") << ", password: " << row[3]
                      << ", upd_date: " << (row[4] ? row[4] : "NULL") << ", NULL: " << row[5] << std::endl;
        } else {
            std::cout << "Record not found for uid: " << uid << std::endl;
        }

        mysql_free_result(result);
    } else {
        std::cerr << "mysql_query() failed" << std::endl;
    }
}
