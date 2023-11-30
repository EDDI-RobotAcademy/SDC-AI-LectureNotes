#include "Post.h"

Post::Post(int id, std::string& title, std::string& writer, std::string& content) : id(id), title(title), writer(writer), content(content) { }

int Post::getid(){
    return id;
}

std::string Post::gettitle(){
    return title;
}

std::string Post::getwriter(){
    return writer;
}

std::string Post::getcontent(){
    return content;
}

Post::~Post() { }