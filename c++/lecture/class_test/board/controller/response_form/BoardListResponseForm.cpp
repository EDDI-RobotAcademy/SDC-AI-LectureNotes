//
// Created by eddi on 23. 12. 7.
//

#include "BoardListResponseForm.h"

BoardListResponseForm::BoardListResponseForm (
        const int boardId, const std::string& title, const std::string& writer)
                                : boardId(boardId), title(title), writer(writer) { }

std::string BoardListResponseForm::getTitle() {
    return title;
}

std::string BoardListResponseForm::getWriter() {
    return writer;
}

int BoardListResponseForm::getBoardId() {
    return boardId;
}
