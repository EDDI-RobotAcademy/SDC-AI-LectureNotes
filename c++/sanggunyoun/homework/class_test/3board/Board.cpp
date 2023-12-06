//
// Created by eddi on 23. 12. 1.
//
#include "Board.h"

#include <iostream>

Board::Board(std::string& _name, std::string& _title, std::string& _post) : _name(_name), _title(_title), _post(_post){ }

std::string Board::name()
{
    return _name;
}

std::string Board::title()
{
    return _title;
}
std::string Board::post()
{
    return  _post;
}

Board::~Board() { }