//
// Created by eddi on 23. 11. 30.
//

#ifndef CPP_CLASS_QUESTIONS_BOARD_H
#define CPP_CLASS_QUESTIONS_BOARD_H

#include <string>

class Board {
private:
    unsigned int id;
    std::string title;
    std::string writer;
    std::string content;

public:
    Board(unsigned int, std::string&, std::string&, std::string&);
    unsigned int getBoardNumber();
    std::string getBoardTitle();
    std::string getBoardWriter();
    std::string getBoardContent();
    ~Board();
};


#endif //CPP_CLASS_QUESTIONS_BOARD_H
