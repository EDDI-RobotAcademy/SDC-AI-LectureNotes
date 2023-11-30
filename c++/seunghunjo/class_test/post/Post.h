//
// Created by eddi on 23. 11. 30.
//

#ifndef CLASS_TEST_POST_H
#define CLASS_TEST_POST_H


#include <string>

class Post {
private:
    std::string writer;
    std::string title;
    std::string content;

public:
    Post(std::string&, std::string&, std::string&);
    std::string getWriter();
    std::string getTitle();
    std::string getContent();
    ~Post();
};


#endif //CLASS_TEST_POST_H
