//
// Created by eddi on 23. 12. 7.
//

#include "BoardModifyRequestForm.h"
#include "../../service/request/BoardModifyRequest.h"

BoardModifyRequestForm::BoardModifyRequestForm(
        const int& boardNo, const std::string& title, const std::string& content)
                                : boardNo(boardNo), title(title), content(content) { }

BoardModifyRequest *BoardModifyRequestForm::toBoardModifyRequest()
{
    return new BoardModifyRequest(boardNo, title, content);
}
