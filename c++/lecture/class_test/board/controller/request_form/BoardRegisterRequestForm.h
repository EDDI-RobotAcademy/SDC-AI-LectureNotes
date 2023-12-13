//
// Created by eddi on 23. 12. 6.
//

#ifndef CLASS_TEST_BOARDREGISTERREQUESTFORM_H
#define CLASS_TEST_BOARDREGISTERREQUESTFORM_H

#include <string>
#include "../../service/request/BoardRegisterRequest.h"

class BoardRegisterRequestForm {
private:
    std::string title;
    int writerSessionId;
    std::string content;

public:
    BoardRegisterRequestForm(const std::string& title, const int writerSessionId, const std::string& content);
    BoardRegisterRequest *toBoardRegisterRequest(std::string writer);

    int getWriterSessionId();
};


#endif //CLASS_TEST_BOARDREGISTERREQUESTFORM_H
