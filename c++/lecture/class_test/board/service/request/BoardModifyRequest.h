//
// Created by eddi on 23. 12. 7.
//

#ifndef CLASS_TEST_BOARDMODIFYREQUEST_H
#define CLASS_TEST_BOARDMODIFYREQUEST_H

#include <string>
#include "../../entity/Board.h"

class BoardModifyRequest {
private:
    int boardNo;
    std::string title;
    std::string content;

public:
    BoardModifyRequest(const int& boardNo, const std::string& title, const std::string& content);
    Board *toBoard();

    int getBoardNo() const;

    const std::string &getTitle() const;

    const std::string &getContent() const;
};


#endif //CLASS_TEST_BOARDMODIFYREQUEST_H
