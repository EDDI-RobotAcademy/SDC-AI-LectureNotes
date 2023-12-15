//
// Created by eddi on 23. 12. 7.
//

#ifndef CLASS_TEST_BOARDREADRESPONSEFORM_H
#define CLASS_TEST_BOARDREADRESPONSEFORM_H

#include <string>

class BoardReadResponseForm {
private:
    std::string title;
    std::string writer;
    std::string content;

public:
    BoardReadResponseForm (const std::string& title, const std::string& writer, const std::string& content);

    std::string getTitle();

    std::string getWriter();

    std::string getContent();
};


#endif //CLASS_TEST_BOARDREADRESPONSEFORM_H
