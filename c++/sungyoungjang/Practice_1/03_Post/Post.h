//
// Created by eddi on 23. 11. 30.
//

#ifndef PRACTICE_1_POST_H
#define PRACTICE_1_POST_H


#include <string>

class Post {
private:
    std::string _title;
    std::string _writer;
    std::string _content;
public:
    Post(std::string&, std::string&, std::string&);
    std::string title();
    std::string writer();
    std::string content();
    ~Post();
};


#endif //PRACTICE_1_POST_H
