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

    DbProcess db(DB_HOST, DB_USER, DB_PASS, DB_NAME);

    if (!db.connect()) {
        std::cerr << "Connection error" << std::endl;
        return 1;
    }

    if (!db.insertData()) {
        std::cerr << "Error during insertion" << std::endl;
    }

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
