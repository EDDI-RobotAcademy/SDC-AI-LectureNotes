//
// Created by eddi on 23. 11. 30.
//

#include "BoardRepositoryImpl.h"
#include "../../mysql/DbProcess.h"

std::vector<Board> fetchResults(MYSQL* conn) {
    std::vector<Board> boardList;

    const std::string& selectQuery = "SELECT * FROM board";

    // mysql_qurry로 select가 살행됨
    if (mysql_query(conn, selectQuery.c_str()) == 0) {
        // result에 결과값이 저장됨
        MYSQL_RES* result = mysql_store_result(conn);
        if (result == nullptr) {
            std::cerr << "mysql_store_result() failed" << std::endl;
            return boardList;
        }

        MYSQL_ROW row;
        // 루프를 돌면서 Board 객체를 만듬
        // 루프를 행 단위로 동작하므로 총 4 번 루프를 돌게 될 것임
        while ((row = mysql_fetch_row(result)) != nullptr) {
            Board board(
                    std::stoi(row[0]),        // board_id
                    row[3],                   // title
                    row[5],                   // writer
                    row[1],                   // content
                    row[2] ? row[2] : "NULL", // reg_date 등록일
                    row[4] ? row[4] : "NULL"  // upd_date 갱신일
            );

            boardList.push_back(board);  // boardList 라는 동적배열에 집어 넣기
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

    // MYSQL 접속 시작
    const char* DB_HOST = "localhost";
    const char* DB_USER = "eddi";
    const char* DB_PASS = "eddi@123";
    const char* DB_NAME = "test_db";

    DbProcess db(DB_HOST, DB_USER, DB_PASS, DB_NAME);

    if (!db.connect()) {
        std::cerr << "Connection error" << std::endl;
    }
    // MYSQL 접속 완료

    // DB 커넥션 boardList 에는 43행에서 리턴한 값이 들어 있
    std::vector<Board> boardList = fetchResults(db.getConn());

    // 처리 결과 확인하는 부분 (없어도 됨)
    for (const auto& board : boardList) {
        board.printBoardInfo();
    }

    return boardList;
}