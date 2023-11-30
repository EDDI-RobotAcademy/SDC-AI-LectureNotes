//
// Created by eddi on 23. 11. 30.
//

#include <iostream>
#include "Post.h"

int post_count = 0;

Post::Post(std::string & _title, std::string & _writer, std::string & _password, std::string & _content) :
       unique_id(post_count), title(_title), writer(_writer), password(_password), content(_content){

    std::cout << "게시물 생성됨" << std::endl;
}

Post::~Post(){
    std::cout << "게시물 삭제됨" << std::endl;
}

void Post::readPost() {
    std::cout << "title: " << title << "\nwriter: " << writer << "\n[content]\n" << content << std::endl;
}

bool Post::checkPassword(std::string & _password) {
    return password == _password;
}

void Post::editPost(std::string & _title, std::string & _content) {
    title = _title;
    content = _content;
}
