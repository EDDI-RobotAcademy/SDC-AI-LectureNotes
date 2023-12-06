//
// Created by eddi on 23. 11. 30.
//

#include "Player.h"

Player::Player(std::string& name, int age) : name(name), age(age) { }


std::string Player::getPlayerName()
{
    return name;
}

int Player::getPlayerAge()
{
    return age;
}

Player::~Player() { }
