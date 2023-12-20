//
// Created by eddi on 23. 12. 6.
//

#include "BoardRegisterRequestForm.h"

BoardRegisterRequestForm::BoardRegisterRequestForm(
        const std::string& title, const int writerSessionId, const std::string& content)
                                        : title(title), writerSessionId(writerSessionId), content(content) { }

BoardRegisterRequest *BoardRegisterRequestForm::toBoardRegisterRequest(std::string writer)
{
    return new BoardRegisterRequest(title, writer, content);
}

int BoardRegisterRequestForm::getWriterSessionId()
{
    return writerSessionId;
}