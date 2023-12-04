//
// Created by eddi on 23. 11. 30.
//

#include "Board.h"

Board::Board(unsigned int id, std::string & title,
             std::string & writer, std::string & content) :
             id(id), title(title), writer(writer), content(content) {}

unsigned int Board::getBoardNumber() {
    return id;
}

std::string Board::getBoardTitle() {
    return title;
}

std::string Board::getBoardWriter() {
    return writer;
}

std::string Board::getBoardContent() {
    return content;
}

Board::~Board() {}