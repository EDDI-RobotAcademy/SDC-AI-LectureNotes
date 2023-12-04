//
// Created by eddi on 23. 11. 30.
//

#ifndef CLASS_TEST_POST_H
#define CLASS_TEST_POST_H

#include <string>

class Post {
private:
    int id;
    std::string title;
    std::string writer;
    std::string content;

public:
    Post(int, std::string&, std::string&, std::string&);
    int getid();
    std::string gettitle();
    std::string getwriter();
    std::string getcontent();
    ~Post();
};

#endif //CLASS_TEST_POST_H