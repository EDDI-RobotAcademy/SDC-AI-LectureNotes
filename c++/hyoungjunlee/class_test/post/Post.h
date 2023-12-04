//
// Created by eddi on 23. 11. 30.
//

#ifndef CLASS_TEST_POST_H
#define CLASS_TEST_POST_H


#include <string>

class Post {
private:
    int postNumber;
    std::string userName;
    std::string title;
    std::string content;

public:
    Post(int,std::string&,std::string&,std::string&);
    int getPostNumber();
    std::string getPostTitle();
    std::string getPostContent();
    std::string getPostUserName();
    ~Post();



};


#endif //CLASS_TEST_POST_H

