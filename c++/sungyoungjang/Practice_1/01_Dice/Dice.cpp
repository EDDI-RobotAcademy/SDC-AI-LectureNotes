//
// Created by eddi on 23. 11. 30.
//

#include <iostream>
#include <random>
#include "Dice.h"

Dice::Dice() {
    std::cout << "주사위 클래스 시작." << std::endl;
}
void Dice::rollDice() {
    std::random_device rand_device;
    std::mt19937 mersenneTwister(rand_device());
    std::uniform_int_distribution<int> distribution(DICE_MIN, DICE_MAX);

    diceNumber = distribution(mersenneTwister);
}

int Dice::getDiceNumber() {
    return diceNumber;
}


Dice::~Dice() {
    std::cout << "주사위 클래스 종료." << std::endl;
}