//
// Created by eddi on 23. 11. 30.
//

#include "Dice.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>

// 생성자와 소멸자는 entity가 있으면 무조건 있어야 하고, return type 이 없다.
Dice::Dice() {
    std::cout << "Dice 생성자" << std::endl;

    //srand(static_cast<unsigned int>(time(0)));
}

void Dice::rollDice() {
    //diceNumber = rand() % (DICE_MAX - DICE_MIN + 1) + DICE_MIN;
    // 아래 방식은 C++ 에서 권장하는 새로운 방식의 랜덤 생성 방법론
    // 메르센 트위스터 알고리즘에 대해 파악하려고하지 말고
    // 아 이렇게 작성하는 구나 하고 넘겨
    // 만약 이것을 파고 싶다면 수학과로 가라
    std::random_device rand_device;
    std::mt19937 mt(rand_device());
    std::uniform_int_distribution<int> distribution(DICE_MIN, DICE_MAX);

    diceNumber = distribution(mt);
}

int Dice::getDiceNumber() {
    return diceNumber;
}

Dice::~Dice() {
    std::cout << "Dice 소멸자" << std::endl;
}