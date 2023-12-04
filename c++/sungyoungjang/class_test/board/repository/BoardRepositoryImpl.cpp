//
// Created by eddi on 23. 11. 30.
//

#include "BoardRepositoryImpl.h"
#include "../../mysql/DbProcess.h"

std::vector<Board> fetchResults(MYSQL* conn) {
    std::vector<Board> boardList;
    // db에는 있지만 void이기 때문에 변형해서 사용해야함;
    const std::string& selectQuery = "SELECT * FROM board";

    //mysql_query로 select가 실행됨
    if (mysql_query(conn, selectQuery.c_str()) == 0) {
        // resulr에 결과값이 저장됨
        MYSQL_RES* result = mysql_store_result(conn);
        if (result == nullptr) {
            std::cerr << "mysql_store_result() failed" << std::endl;
            return boardList;
        }

        MYSQL_ROW row;
        // 루프를 돌면서 Board 객체를 만듬
        // 루프를 행 단위로 동작하므로 총 4번 루프를 돌게
        while ((row = mysql_fetch_row(result)) != nullptr) {
            Board board(
                    std::stoi(row[0]),        // board_id
                    row[3],                   // title
                    row[5],                   // writer
                    row[1],                   // content
                    row[2] ? row[2] : "NULL", // reg_date
                    row[4] ? row[4] : "NULL"  // upd_date
            );

            boardList.push_back(board);
            // boardList.라는 동적배열에 할당함 위의 내용을
        }

        mysql_free_result(result);
    } else {
        std::cerr << "mysql_query() failed" << std::endl;
    }

    return boardList;
}

std::vector<Board> BoardRepositoryImpl::findAll()
{
    std::cout << "BoardReopository: 리스트 전체 출력!" << std::endl;
    // mysql 접속시작
    const char* DB_HOST = "localhost";
    const char* DB_USER = "eddi";
    const char* DB_PASS = "eddi@123";
    const char* DB_NAME = "test_db";

    DbProcess db(DB_HOST, DB_USER, DB_PASS, DB_NAME);

    if (!db.connect()) {
        std::cerr << "Connection error" << std::endl;
    }
    // mysql 접속완료

    std::vector<Board> boardList = fetchResults(db.getConn()); // db.getConn -> 저장된 데이터 불러오기

    // 처리 결과 학인하는 부분
//    for (const auto& board : boardList) {
//        board.printBoardInfo();
//    }

    return boardList;
}