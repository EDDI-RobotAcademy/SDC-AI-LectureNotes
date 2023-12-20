//
// Created by eddi on 23. 11. 30.
//

#ifndef CLASS_TEST_BOARDREGISTERRESPONSE_H
#define CLASS_TEST_BOARDREGISTERRESPONSE_H

#include <string>
#include "../../controller/response_form/BoardRegisterResponseForm.h"

class BoardRegisterResponse {
private:
    std::string title;
    std::string writer;
    std::string content;

public:
    BoardRegisterResponse (const std::string& title, const std::string& writer, const std::string& content);
    BoardRegisterResponseForm *toBoardRegisterResponseForm();
};


#endif //CLASS_TEST_BOARDREGISTERRESPONSE_H
