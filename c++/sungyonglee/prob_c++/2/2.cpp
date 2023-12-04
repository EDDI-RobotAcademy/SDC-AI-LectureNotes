//
// Created by eddi on 23. 11. 30.
//

#include <iostream>
#include "2.h"

// 2. 사용자 클래스를 만들어 봅시다.

Player::Player(std::string& name, int age, int height) : name(name), age(age), height(height) { }

std::string Player::getPlayerName()
{
    return name;
}

int Player::getPlayerAge()
{
    return age;
}

int Player::getPlayerHeight()
{
    return height;
}
Player::~Player() { }