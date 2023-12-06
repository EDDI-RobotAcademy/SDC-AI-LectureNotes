//
// Created by eddi on 23. 12. 6.
//

#ifndef CLASS_TEST_BOARDREGISTERRESPONSEFORM_H
#define CLASS_TEST_BOARDREGISTERRESPONSEFORM_H

#include <string>

class BoardRegisterResponseForm {
private:
    std::string title;
    std::string writer;
    std::string content;

public:
    BoardRegisterResponseForm (const std::string& title, const std::string& writer, const std::string& content);
};


#endif //CLASS_TEST_BOARDREGISTERRESPONSEFORM_H
