//
// Created by eddi on 23. 11. 30.
//

// 3. 게시물 클래스를 만들어 봅시다.

#include "3.h"

Post::Post(std::string& title, std::string& writer, std::string& content) : title(title), writer(writer), content(content) { }

std::string Post::getPostTitle()
{
    return title;
}

std::string Post::getPostWriter()
{
    return writer;
}

std::string Post::getPostContent()
{
    return content;
}
Post::~Post() { }