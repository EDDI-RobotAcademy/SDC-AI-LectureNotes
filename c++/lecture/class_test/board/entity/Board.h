//
// Created by eddi on 23. 11. 30.
//

#ifndef CLASS_TEST_BOARD_H
#define CLASS_TEST_BOARD_H


#include <string>
#include <chrono>
#include <iostream>
#include <tuple>

class Board {
private:
    int id;
    std::string title;
    std::string writer;
    std::string content;

    std::chrono::system_clock::time_point created_at;
    std::chrono::system_clock::time_point updated_at;

public:
    Board();
    Board(const std::string& title, const std::string& writer, const std::string& content);
    Board(int id, const std::string& title, const std::string& writer, const std::string& content);
    Board(int id, const std::string& title, const std::string& writer, const std::string& content,
          const std::string& reg_date, const std::string& upd_date);

    const std::string &getTitle() const;
    const std::string &getWriter() const;
    const std::string &getContent() const;

    void printBoardInfo() const;

    void initializeFromRow(int id,
                           const std::string& title,
                           const std::string& writer,
                           const std::string& content,
                           const std::string& reg_date,
                           const std::string& upd_date) {
        this->id = id;
        this->title = title;
        this->writer = writer;
        this->content = content;

        this->created_at = std::chrono::system_clock::from_time_t(std::stoi(reg_date));
        this->updated_at = std::chrono::system_clock::from_time_t(std::stoi(upd_date));
    }

    static auto getAttributes() {
        return std::make_tuple(&Board::id, &Board::title, &Board::writer,
                               &Board::content, &Board::created_at, &Board::updated_at);
    }
};


#endif //CLASS_TEST_BOARD_H
