//
// Created by eddi on 23. 12. 6.
//

#include "BoardRegisterRequest.h"

BoardRegisterRequest::BoardRegisterRequest(
        const std::string& title, std::string& writer, const std::string& content)
                                : title(title), writer(writer), content(content) { }

Board *BoardRegisterRequest::toBoard()
{
    return new Board(title, writer, content);
}
