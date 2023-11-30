//
// Created by eddi on 23. 11. 30.
//

#ifndef CLASS_TEST_POST_H
#define CLASS_TEST_POST_H

#include <string>
extern int post_count;

class Post {
private:
    int unique_id;
    std::string title;
    std::string writer;
    std::string password;
    std::string content;
public:
    Post(std::string&, std::string&, std::string&, std::string&);
    void readPost();
    bool checkPassword(std::string&);
    void editPost(std::string&, std::string&);

    ~Post();
};



#endif //CLASS_TEST_POST_H
