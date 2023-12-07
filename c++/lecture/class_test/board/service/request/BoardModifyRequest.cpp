//
// Created by eddi on 23. 12. 7.
//

#include "BoardModifyRequest.h"

BoardModifyRequest::BoardModifyRequest(
        const int& boardNo, const std::string& title, const std::string& content)
                                : boardNo(boardNo), title(title), content(content) { }

Board *BoardModifyRequest::toBoard()
{
    return new Board();
}

int BoardModifyRequest::getBoardNo() const {
    return boardNo;
}

const std::string &BoardModifyRequest::getTitle() const {
    return title;
}

const std::string &BoardModifyRequest::getContent() const {
    return content;
}
