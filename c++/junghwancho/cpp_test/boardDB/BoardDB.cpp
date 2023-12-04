//
// Created by eddi on 23. 12. 4.
//

#include <iostream>
#include "BoardDB.h"
#include "../mysql_test/DbProcess.h"
#include "../api/BoardApi.h"
#include "../api/BoardApiTableMapper.h"

int BoardDB::boardDBCall() {

    const char *DB_HOST = "localhost";
    const char *DB_USER = "eddi";
    const char *DB_PASS = "eddi@123";
    const char *DB_NAME = "test_db";
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

// 다음으로 db 객체의 insertData 함수(매서드)를 실행
// insertData(db) <- C에서는 이런 형태로 사용했었음
// 데이터 생성(게시물 생성)
    if (!db.insertDataBoard()) {
        std::cerr << "Error during board insertion" << std::endl;
    }

// 데이터 전체 조회(리스트)

    db.selectBoardData();

    int updateBoardId = 3;
    std::string newTitle = "Updated Title";
    std::string newContent = "Updated Content";
    if (db.updateDataBoard(updateBoardId, newTitle, newContent)) {
        std::cout << "Record updated successfully" << std::endl;
    } else {
        std::cerr << "Error updating board record" << std::endl;
    }

    std::cout << "---- All Records After Update ----" << std::endl;
    db.selectBoardData();

    int deleteBoardId = 3;
    if (db.deleteBoardData(deleteBoardId)) {
        std::cout << "Record board deleted successfully" << std::endl;
    } else {
        std::cerr << "Error deleting board record" << std::endl;
    }

    std::cout << "---- All Records After Delete ----" << std::endl;
    db.selectBoardData();

    int readBoardId = 4;
    std::cout << "---- Read board Record ----" << std::endl;
    db.readBoardData(readBoardId);

    return 0;
}

BoardDB::BoardDB() {

}
