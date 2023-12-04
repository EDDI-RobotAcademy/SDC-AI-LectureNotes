//
// Created by eddi on 23. 12. 4.
//

#include <iostream>
#include "AccountDB.h"
#include "../mysql_test/DbProcess.h"

int AccountDB::accountDBCall() {

    const char* DB_HOST = "localhost";
    const char* DB_USER = "eddi";
    const char* DB_PASS = "eddi@123";
    const char* DB_NAME = "test_db";
    DbProcess db(DB_HOST, DB_USER, DB_PASS, DB_NAME);

// 다음으로 db 객체의 insertData 함수(매서드)를 실행
// insertData(db) <- C에서는 이런 형태로 사용했었음
// 데이터 생성(게시물 생성)
    if (!db.insertDataAccount())
        std::cerr << "Error during account insertion" << std::endl;
    if (!db.connect()) {
        std::cerr << "Connection error" << std::endl;
        return 1;
    }

// 데이터 전체 조회(리스트)
    db.selectBoardData();

    int updateAccountId = 2;
    std::string newName = "Updated Title";
    std::string newPassword = "Updated Content";
    if (db.updateDataAccount(updateAccountId, newName, newPassword)) {
        std::cout << "Record updated successfully" << std::endl;
    } else {
        std::cerr << "Error updating record" << std::endl;
    }

    std::cout << "---- All Records After Update ----" << std::endl;
    db.selectAccountData();

    int deleteAccountId = 3;
    if (db.deleteAccountData(deleteAccountId)) {
        std::cout << "Record deleted successfully" << std::endl;
    } else {
        std::cerr << "Error deleting record" << std::endl;
    }

    std::cout << "---- All Records After Delete ----" << std::endl;
    db.selectAccountData();

    int readAccountId = 4;
    std::cout << "---- Read Record ----" << std::endl;
    db.readAccountData(readAccountId);

    return 0;
}

AccountDB::AccountDB() {

}

