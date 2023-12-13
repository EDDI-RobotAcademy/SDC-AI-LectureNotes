//
// Created by eddi on 23. 11. 30.
//

#include <iostream>
#include "Board.h"


Board::Board(std::string& writer, std::string& title, std::string& contents)
: writer(writer), title(title), contents(contents)
{
    std::cout << "board 생성자" << std::endl;
}

std::string Board::getWriterLength()
{
    return writer;
}
std::string Board::getTitleLength()
{
    return title;
}
std::string Board::getContentsLength()
{
    return contents;
}

Board::~Board()
{
    std::cout << "board 소멸자" << std::endl;
}