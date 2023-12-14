#include <iostream>

//#include "api/BoardApi.h"
//#include "api/BoardApiTable.h"

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

    std::string accountID = "test_account";
    std::string password = "1234";
    if (!db.insertAccountData(accountID, password)) {
        
        std::cerr << "Error during account insertion" << std::endl;
    }
        std::string content = "뭐 쓸까 ?";
        std::string title = "이거 되냐";
        std::string writer = "J";
    if (!db.insertBoardData(content, title, writer)) {

        std::cerr << "Error during board insertion" << std::endl;
    }

    db.selectAccountData();
    int updateAccountId = 2;
    std::string newAccount_id = "아이디 수정했슈";
    std::string newPassword = "비밀번호 수정했슈";
    if (db.updateAccountData(updateAccountId, newAccount_id, newPassword)) {
        std::cout << "Record account updated successfully" << std::endl;
    } else {
        std::cerr << "Error account updating record" << std::endl;
    }

    std::cout << "---- All Records After Account Update ----" << std::endl;

    db.selectBoardData();

    int updateBoardId = 2;
    std::string newTitle = "제목 수정했슈";
    std::string newContent = "내용 수정했슈";
    if (db.updateBoardData(updateBoardId, newTitle, newContent)) {
        std::cout << "Record board updated successfully" << std::endl;
    } else {
        std::cerr << "Error board updating record" << std::endl;
    }

    std::cout << "---- All Records After Board Update ----" << std::endl;

    db.selectAccountData();
    int deleteAccountId = 3;
    if (db.deleteAccountData(deleteAccountId)) {
        std::cout << "Record account deleted successfully" << std::endl;
    } else {
        std::cerr << "Error account deleting record" << std::endl;
    }

    std::cout << "---- All Records After Account Delete ----" << std::endl;


    db.selectBoardData();
    int deleteBoardId = 3;
    if (db.deleteBoardData(deleteBoardId)) {
        std::cout << "Record board deleted successfully" << std::endl;
    } else {
        std::cerr << "Error board deleting record" << std::endl;
    }

    std::cout << "---- All Records After Board Delete ----" << std::endl;

    db.selectAccountData();

    int readAccountId = 4;
    std::cout << "---- Read Record ----" << std::endl;
    db.readAccountData(readAccountId);

    db.selectBoardData();

    int readBoardId = 4;
    std::cout << "---- Read Record ----" << std::endl;
    db.readBoardData(readBoardId);

    return 0;
}
