//
// Created by eddi on 23. 11. 30.
//

#include "BoardRepositoryImpl.h"
#include "../../mysql/DbProcess.h"

std::vector<Board> fetchResults(MYSQL* conn) {
    std::vector<Board> boardList;

    const std::string& selectQuery = "SELECT * FROM board";

    if (mysql_query(conn, selectQuery.c_str()) == 0) {
        MYSQL_RES* result = mysql_store_result(conn);
        if (result == nullptr) {
            std::cerr << "mysql_store_result() failed" << std::endl;
            return boardList;
        }

        MYSQL_ROW row;
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


    const char* DB_HOST = "localhost";
    const char* DB_USER = "eddi";
    const char* DB_PASS = "eddi@123";
    const char* DB_NAME = "test_db";
    //DbProcess db mysql데이터베이스 로그인 및 test_db실행
    DbProcess db(DB_HOST, DB_USER, DB_PASS, DB_NAME);

    if (!db.connect()) {
        std::cerr << "Connection error" << std::endl;
    }

    std::vector<Board> boardList = fetchResults(db.getConn());

    for (const auto& board : boardList) {
        board.printBoardInfo();
    }

    return boardList;
}