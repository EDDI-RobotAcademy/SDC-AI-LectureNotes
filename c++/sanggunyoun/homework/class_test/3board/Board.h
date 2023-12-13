//
// Created by eddi on 23. 11. 30.
//

#ifndef CLASS_TEST_BOARD_H
#define CLASS_TEST_BOARD_H


#include <string>

class Board{

private:
    std::string _name;
    std::string _title;
    std::string _post;




public:
    Board(std::string&, std::string&, std::string&);
    std::string name();
    std::string title();
    std::string post();
    ~Board();

};


#endif //CLASS_TEST_BOARD_H
