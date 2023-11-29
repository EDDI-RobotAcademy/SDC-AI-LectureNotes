#include <iostream>

#include "api/BoardApi.h"
#include "api/BoardApiTable.h"

#include "mysql_test/DbProcess.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

//    int api_index = static_cast<int>(BoardAPI::LIST);
//    board_api_table[api_index](nullptr);

    const char* DB_HOST = "localhost";
    const char* DB_USER = "eddi";
    const char* DB_PASS = "eddi@123";
    const char* DB_NAME = "test_db";

    // 생성자 호출
    // 사실상 C에서 init_db_process_object()와 같은 역할임
    // DbProcess 라는 이름의 함수가
    // DB_HOST, DB_USER, DB_PASS, DB_NAME을 가지고 실행되는 것
    DbProcess db(DB_HOST, DB_USER, DB_PASS, DB_NAME);

    // db라는 변수는 위의 정보를 토대로하는 객체임
    // 만약 연결이 잘 되었다면 1이 리턴되며
    // 연결에 문제가 발생했다면 0이 리턴됨
    if (!db.connect()) {
        std::cerr << "Connection error" << std::endl;
        return 1;
    }

    // 다음으로 db 객체의 insertData 함수(매서드)를 실행
    // insertData(db) <- C에서는 이런 형태로 사용했었음
    // 데이터 생성(게시물 생성)
    if (!db.insertData()) {
        std::cerr << "Error during insertion" << std::endl;
    }

    // 데이터 전체 조회(리스트)
    db.selectData();

    int updateBoardId = 3;
    std::string newTitle = "Updated Title";
    std::string newContent = "Updated Content";
    if (db.updateData(updateBoardId, newTitle, newContent)) {
        std::cout << "Record updated successfully" << std::endl;
    } else {
        std::cerr << "Error updating record" << std::endl;
    }

    std::cout << "---- All Records After Update ----" << std::endl;
    db.selectData();

    int deleteBoardId = 3;
    if (db.deleteData(deleteBoardId)) {
        std::cout << "Record deleted successfully" << std::endl;
    } else {
        std::cerr << "Error deleting record" << std::endl;
    }

    std::cout << "---- All Records After Delete ----" << std::endl;
    db.selectData();

    int readBoardId = 4;
    std::cout << "---- Read Record ----" << std::endl;
    db.readData(readBoardId);

    return 0;
}
