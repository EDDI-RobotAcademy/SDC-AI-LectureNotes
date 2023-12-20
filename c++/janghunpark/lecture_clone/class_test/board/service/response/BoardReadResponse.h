//
// Created by eddi on 23. 12. 7.
//

#ifndef CLASS_TEST_BOARDREADRESPONSE_H
#define CLASS_TEST_BOARDREADRESPONSE_H

#include <string>
#include "../../controller/response_form/BoardReadResponseForm.h"

class BoardReadResponse {
private:
    std::string title;
    std::string writer;
    std::string content;

public:
    BoardReadResponse (const std::string& title, const std::string& writer, const std::string& content);
    BoardReadResponseForm *toBoardReadResponseForm();
};


#endif //CLASS_TEST_BOARDREADRESPONSE_H
