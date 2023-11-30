//
// Created by eddi on 23. 11. 30.
//

#include "Dice.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

Dice::Dice() {
    std::cout << "마! 내가 생성자다!" << std::endl;

    srand(static_cast<unsigned int>(time(0)));
}

void Dice::rollDice() {
    diceNumber = rand() % (DICE_MAX - DICE_MIN + 1) + DICE_MIN;
}

int Dice::getDiceNumber() {
    return diceNumber;
}

Dice::~Dice() {
    std::cout << "난 뒤질 때 출력됨" << std::endl;
}