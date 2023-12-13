//
// Created by eddi on 23. 11. 30.
//

#include <iostream>
#include "Player.h"
Player::Player(std::string& name, int PlayNumber) : name(name), PlayerNumber(PlayNumber) { }
std::string Player::getPlayerName() {
    return name;
};
int Player::getPlayerNumber()
{
    return PlayerNumber;
}
Player::~Player() {
    std::cout << "사용자 종료." << std::endl;
}