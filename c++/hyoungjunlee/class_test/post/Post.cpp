//
// Created by eddi on 23. 11. 30.
//

#include <iostream>
#include "Post.h"
Post::Post(int postNumber,std::string& userName,std::string& title,std::string& content) : postNumber(postNumber),
                                                                                           userName(userName),
                                                                                           title(title),
                                                                                           content(content)
{

}
int Post::getPostNumber()
{
    return postNumber;
}
std::string Post::getPostTitle()
{
    return title;
}
std::string Post::getPostContent()
{
    return content;
}
std::string Post::getPostUserName()
{
    return userName;
}
Post::~Post()
{
    std::cout<<"게시물 소멸자 자동 실행!"<<std::endl;
}

//Player::Player(std::string& name, int age) : name(name), age(age) { }
//
//std::string Player::getPlayerName()
//{
//    return name;
//}
//
//int Player::getPlayerAge()
//{
//    return age;
//}
//
//Player::~Player() {}