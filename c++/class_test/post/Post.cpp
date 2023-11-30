//
// Created by eddi on 23. 11. 30.
//

#include <iostream>
#include "Post.h"

Post::Post(std::string & _title, std::string & _writer, std::string & _password, std::string & _content) :
       unique_id(post_count), title(_title), writer(_writer), password(_password), content(_content){

    std::cout << "게시물 생성됨" << std::endl;
}

Post::~Post(){
    std::cout << "게시물 삭제됨" << std::endl;
}