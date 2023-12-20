//
// Created by eddi on 23. 12. 7.
//

#ifndef CLASS_TEST_BOARDLISTRESPONSEFORM_H
#define CLASS_TEST_BOARDLISTRESPONSEFORM_H

#include <string>

class BoardListResponseForm {
private:
    int boardId;
    std::string title;
    std::string writer;

public:
    BoardListResponseForm (const int boardId, const std::string& title, const std::string& writer);

    std::string getTitle();

    std::string getWriter();

    int getBoardId();
};


#endif //CLASS_TEST_BOARDLISTRESPONSEFORM_H
