//
// Created by eddi on 23. 11. 30.
//

#include "Player.h"

// 클래스 내에 있는 name에 입력 name을 배치
// name(name)에서 name() 부분이 클래스 내부 변수
// 소괄호 내부의 name이 입력 파라미터
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