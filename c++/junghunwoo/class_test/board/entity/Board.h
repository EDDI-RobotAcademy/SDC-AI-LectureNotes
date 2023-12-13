//
// Created by eddi on 23. 11. 30.
//

#ifndef CLASS_TEST_BOARD_H
#define CLASS_TEST_BOARD_H


#include <string>
#include <chrono>
#include <iostream>

class Board {
private:
    int id;
    std::string title;
    std::string writer;
    std::string content;

    std::chrono::system_clock::time_point created_at;
    std::chrono::system_clock::time_point updated_at;

public:
    Board(int id, const std::string& title, const std::string& writer, const std::string& content);
    Board(int id, const std::string& title, const std::string& writer, const std::string& content,
          const std::string& reg_date, const std::string& upd_date);

    void printBoardInfo() const;
};


#endif //CLASS_TEST_BOARD_H
