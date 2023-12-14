//
// Created by eddi on 23. 12. 7.
//

#ifndef CLASS_TEST_BOARDMODIFYREQUESTFORM_H
#define CLASS_TEST_BOARDMODIFYREQUESTFORM_H

#include <string>
#include "../../service/request/BoardModifyRequest.h"

class BoardModifyRequestForm {
private:
    int boardNo;
    std::string title;
    std::string content;

public:
    BoardModifyRequestForm(const int& boardNo, const std::string& title, const std::string& content);
    BoardModifyRequest *toBoardModifyRequest();
};


#endif //CLASS_TEST_BOARDMODIFYREQUESTFORM_H
