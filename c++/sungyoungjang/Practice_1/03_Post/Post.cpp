//
// Created by eddi on 23. 11. 30.
//

#include <iostream>
#include "Post.h"

Post::Post(std::string& _title, std::string& _writer, std::string& _content) : _title(_title), _writer(_writer), _content(_content){ }

std::string Post::title() {
    return _title;
}
std::string Post::writer() {
    return _writer;
}
std::string Post::content() {
    return _content;
}
Post::~Post() {
    std::cout << "게시글 종료" << std::endl;
}
