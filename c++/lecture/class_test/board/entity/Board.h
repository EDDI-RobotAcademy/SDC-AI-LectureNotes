//
// Created by eddi on 23. 11. 30.
//

#ifndef CLASS_TEST_BOARD_H
#define CLASS_TEST_BOARD_H


#include <string>
#include <chrono>
#include <iostream>
#include <tuple>
#include <iomanip>
#include <vector>

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
    const int &getId() const;

    void setId(int id);

    void setTitle(const std::string &title);
    void setContent(const std::string &content);

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

    void initializeFromRow(const std::vector<std::string>& values) {
        if (values.size() != attributeCount) {
            throw std::runtime_error("Mismatch in attribute count");
        }

        id = std::stoi(values[0]);
        title = values[1];
        writer = values[2];
        content = values[3];

        created_at = std::chrono::system_clock::from_time_t(std::stoi(values[4]));
        updated_at = values[5].empty() ? created_at : std::chrono::system_clock::from_time_t(std::stoi(values[5]));
    }

    static constexpr size_t attributeCount = 6;

    static auto getAttributes() {
        return std::make_tuple(&Board::id, &Board::title, &Board::writer,
                               &Board::content, &Board::created_at, &Board::updated_at);
    }
};


#endif //CLASS_TEST_BOARD_H
