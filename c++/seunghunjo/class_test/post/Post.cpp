//
// Created by eddi on 23. 11. 30.
//

#include "Post.h"


Post::Post(std::string& writer, std::string& title, std::string& content) : writer(writer), title(title), content(content) { }

 std::string Post::getWriter() {
    return writer;
}

std::string Post::getTitle() {
    return title;
}

std::string Post::getContent() {
    return writer;
}
Post::~Post(){ }