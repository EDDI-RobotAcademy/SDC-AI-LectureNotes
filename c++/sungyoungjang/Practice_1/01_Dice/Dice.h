//
// Created by eddi on 23. 11. 30.
//

#ifndef PRACTICE_1_DICE_H
#define PRACTICE_1_DICE_H


class Dice {
private:
const int DICE_MAX = 6;
const int DICE_MIN = 1;
int diceNumber;

public:
Dice();
void rollDice();
int getDiceNumber();
~Dice();
};


#endif //PRACTICE_1_DICE_H
