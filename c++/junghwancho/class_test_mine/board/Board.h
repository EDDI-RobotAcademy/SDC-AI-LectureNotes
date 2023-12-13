//
// Created by eddi on 23. 11. 30.
//

#ifndef CLASS_TEST_BOARD_H
#define CLASS_TEST_BOARD_H


#include <string>

#define MAX_WRITER_LENGTH 32
#define MAX_title_LENGTH 32
#define MAX_contents_LENGTH 32

class Board {

private:
    std::string writer;
    std::string title;
    std::string contents;

public:
    Board(std::string&, std::string&, std::string&);
    std::string getWriterLength();
    std::string getTitleLength();
    std::string getContentsLength();
    ~Board();
};




#endif //CLASS_TEST_BOARD_H
