//
// Created by eddi on 23. 11. 30.
//

#include "BoardRepositoryImpl.h"
#include "../../mysql/DbProcess.h"

std::vector<Board> fetchResults(MYSQL* conn) {
    std::vector<Board> boardList;

    const std::string& selectQuery = "SELECT * FROM board";

    // mysql_query로 select가 실행됨
    if (mysql_query(conn, selectQuery.c_str()) == 0) {
        // result에 결과값이 저장됨
        MYSQL_RES* result = mysql_store_result(conn);
        if (result == nullptr) {
            std::cerr << "mysql_store_result() failed" << std::endl;
            return boardList;
        }

        MYSQL_ROW row;
        // 루프를 돌면서 Board 객체를 만듬
        // 루프를 행 단위로 동작하므로 총 4번 루프를 돌게 될 것임
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

//    // MYSQL 접속 시작
//    const char* DB_HOST = "localhost";
//    const char* DB_USER = "eddi";
//    const char* DB_PASS = "eddi@123";
//    const char* DB_NAME = "test_db";
//
//    DbProcess db(DB_HOST, DB_USER, DB_PASS, DB_NAME);
//
//    if (!db.connect()) {
//        std::cerr << "Connection error" << std::endl;
//    }
    // MYSQL 접속 완료
    DbProcess* dbInstance = DbProcess::getInstance();

    std::vector<Board> boardList = fetchResults(dbInstance->getConn());

    // 처리 결과 확인하는 부분
//    for (const auto& board : boardList) {
//        board.printBoardInfo();
//    }

    return boardList;
}

Board *BoardRepositoryImpl::save(Board *board)
{
    DbProcess* dbInstance = DbProcess::getInstance();
    std::string title = board->getTitle();
    std::string writer = board->getWriter();
    std::string content = board->getContent();

    std::string queryString = "INSERT INTO board (title, writer, content) VALUES \
                          ('" + title + "', '" + writer + "', '" + content + "' )";

    //dbInstance->insertData(queryString);
    //std::unique_ptr<Board> insertedBoardPtr = dbInstance->insertEntityData<Board>(queryString);
    //Board* insertedBoard = dbInstance->insertOldEntityData<Board>(queryString);
    //std::unique_ptr<Board> insertedBoardPtr = dbInstance->insertDataAfterReturnEntity<Board>(queryString);

    //dbInstance->insertData(queryString);
    if (mysql_query(dbInstance->getConn(), queryString.c_str()) == 0) {
        // Query executed successfully

        // Retrieve the last inserted ID
        unsigned long long lastInsertedId = mysql_insert_id(dbInstance->getConn());
        board->setId(lastInsertedId);
    }

    return board;
    //return insertedBoardPtr.release();
    //return insertedBoard;
}

std::chrono::system_clock::time_point convertBoardStringToTimePoint(const std::string& str) {
    std::cout << "Attempting to parse date string: " << str << std::endl;

    std::tm tm = {};
    std::istringstream ss(str);
    ss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");

    if (ss.fail()) {
        throw std::runtime_error("Error parsing date string");
    }

    std::time_t time = std::mktime(&tm);
    if (time == -1) {
        throw std::runtime_error("Error converting time");
    }

    return std::chrono::system_clock::from_time_t(time);
}

Board constructBoardFromRow(MYSQL_ROW row) {
    int board_id = std::stoi(row[0]);
    std::string title = row[1];
    std::string writer = row[2];
    std::string content = row[3];

    std::string reg_date_str = row[4];
    std::string upd_date_str = row[5];

    std::chrono::system_clock::time_point reg_date = convertBoardStringToTimePoint(reg_date_str);
    std::chrono::system_clock::time_point upd_date = convertBoardStringToTimePoint(upd_date_str);

    if (!reg_date_str.empty() && !upd_date_str.empty()) {
        return Board(board_id, title, writer, content, reg_date_str, upd_date_str);
    } else {
        return Board(board_id, title, writer, content);
    }
}

std::optional<Board> BoardRepositoryImpl::findById(int boardNo)
{
    DbProcess* dbInstance = DbProcess::getInstance();

    std::string queryString = "SELECT board_id, title, writer, content, reg_date, upd_date FROM board WHERE board_id = '" + std::to_string(boardNo) + "'";

    MYSQL_ROW row = dbInstance->findRowData(queryString);

    if (row != nullptr) {
        Board board = constructBoardFromRow(row);
        return std::make_optional(board);
    }

    return std::nullopt;
}

void BoardRepositoryImpl::deleteById(int boardNo)
{
    DbProcess* dbInstance = DbProcess::getInstance();

    std::string queryString = "DELETE FROM board WHERE board_id = '" + std::to_string(boardNo) + "'";

    dbInstance->deleteData(queryString);
}

BoardRepositoryImpl& BoardRepositoryImpl::getInstance() {
    static BoardRepositoryImpl instance;
    return instance;
}
