//
// Created by eddi on 23. 11. 30.
//

#include <iostream>
#include "Player.h"

// 클래스 내에 있는 name에 입력 _name을 배치
// name(_name)에서 name()부분이 클래스 내부 변수
// 소괄호 내부의 _name이 입력 파라미터
Player::Player(std::string& _name, int _age) : name(_name), age(_age){
    std::cout << "생성 완료!" << std::endl;
}



int Player::getPlayerAge() {
    return age;
}

std::string Player::getPlayerName() {
    return name;
}

Player::~Player() {
    std::cout << "~사라진다~" << std::endl;
}