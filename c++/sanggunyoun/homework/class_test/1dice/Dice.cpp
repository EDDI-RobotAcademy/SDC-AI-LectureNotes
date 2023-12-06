//
// Created by eddi on 23. 11. 30.
//

#include "Dice.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

#include <random>

Dice::Dice() {
    std::cout << "주사위 굴러가유!" <<  std::endl;
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
    std::cout << "턴 종료" << std::endl;
}