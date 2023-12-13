//
// Created by eddi on 23. 11. 30.
//

#include <iostream>
#include "Player.h"

// 클래스 내에 있는 name에 입력 name을 배치
// name(name)에서 name() 부분이 클래스 내부 변수
// 소괄호 내부의 name이 입력 파라미터
// 생성자
Player::Player(std::string& name, int age) : name(name), age(age)
{
    std::cout << "player 생성자" << std::endl;
} // 배열에 들어오는 것은 name, age 순서로 저장해라

std::string Player::getPlayerName() // std::string = char *
{
    return name;
}
int Player::getPlayerAge()
{
    return age;
}

// 소멸자
Player::~Player()
{
    std::cout << "player 소멸자" << std::endl;
}