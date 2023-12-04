//
// Created by eddi on 23. 11. 30.
//

#include "dice.h"

#include <iostream>

#include <random>

dice::dice() {}

void dice::rollDice() {
    std::random_device rand_device;
    std::mt19937 mersenneTwister(rand_device());
    std::uniform_int_distribution<int> distribution(DICE_MIN, DICE_MAX);

    diceNumber = distribution(mersenneTwister);
}

int dice::getDiceNumber() {
    return diceNumber;
}

dice::~dice() {}