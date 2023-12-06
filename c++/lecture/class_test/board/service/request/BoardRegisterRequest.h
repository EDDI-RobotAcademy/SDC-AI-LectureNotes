//
// Created by eddi on 23. 12. 6.
//

#ifndef CLASS_TEST_BOARDREGISTERREQUEST_H
#define CLASS_TEST_BOARDREGISTERREQUEST_H

#include <string>
#include "../../entity/Board.h"

class BoardRegisterRequest {
private:
    std::string title;
    std::string writer;
    std::string content;

public:
    BoardRegisterRequest(const std::string& title, std::string& writer, const std::string& content);
    Board *toBoard();
};


#endif //CLASS_TEST_BOARDREGISTERREQUEST_H
