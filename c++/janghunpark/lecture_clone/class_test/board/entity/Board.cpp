//
// Created by eddi on 23. 11. 30.
//

#include "Board.h"

Board::Board() { }

Board::Board(const std::string& title, const std::string& writer, const std::string& content)
        : title(title),
          writer(writer),
          content(content),
          created_at(std::chrono::system_clock::now()),
          updated_at(created_at) { }

Board::Board(int id, const std::string& title, const std::string& writer, const std::string& content)
        : id(id),
          title(title),
          writer(writer),
          content(content),
          created_at(std::chrono::system_clock::now()),
          updated_at(created_at) { }

Board::Board(int id, const std::string& title, const std::string& writer, const std::string& content,
      const std::string& reg_date, const std::string& upd_date)
        : id(id),
          title(title),
          writer(writer),
          content(content) {
    // reg_date, upd_date를 이용하여 시간 설정 (형식에 따라 변경이 필요할 수 있음)
    created_at = std::chrono::system_clock::from_time_t(std::stoi(reg_date));
    updated_at = upd_date.empty() ? created_at : std::chrono::system_clock::from_time_t(std::stoi(upd_date));
}

void Board::printBoardInfo() const {
    std::cout << "ID: " << id
        << ", Title: " << title
        << ", Writer: " << writer
        << ", Content: " << content
        << ", Created At: " << std::chrono::system_clock::to_time_t(created_at)
        << ", Updated At: " << std::chrono::system_clock::to_time_t(updated_at) << std::endl;
}

const int &Board::getId() const {
    return id;
}

const std::string &Board::getTitle() const {
    return title;
}

const std::string &Board::getWriter() const {
    return writer;
}

const std::string &Board::getContent() const {
    return content;
}

void Board::setTitle(const std::string &title) {
    Board::title = title;
}

void Board::setContent(const std::string &content) {
    Board::content = content;
}

void Board::setId(int id) {
    Board::id = id;
}
