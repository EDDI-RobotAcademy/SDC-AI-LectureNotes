//
// Created by eddi on 23. 11. 30.
//

// 1. 주사위를 만들어 봅시다.

#include <iostream>
#include <random>
#include "1.h"

Dice::Dice(){
    std::cout << "1번 문제" << std::endl;
}

void Dice::rollDice(){
    std::random_device rand_device;
    std::mt19937 mersenneTwister(rand_device());
    std::uniform_int_distribution<int> distribution(DICE_MIN, DICE_MAX);

    diceNumber = distribution(mersenneTwister);
}

int Dice::getDiceNumber(){
    return diceNumber;
}

Dice::~Dice() {
    std::cout << "다이스 종료\n" << std::endl;
}