//
// Created by eddi on 23. 11. 30.
//

#ifndef PROB_C___3_H
#define PROB_C___3_H

#include <string>

class Post {
private:
    std::string title;
    std::string writer;
    std::string content;

public:
    Post(std::string &, std::string &, std::string &);
    std::string getPostTitle();
    std::string getPostWriter();
    std::string getPostContent();
    ~Post();
};

#endif //PROB_C___3_H