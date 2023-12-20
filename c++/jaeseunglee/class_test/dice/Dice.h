//
// Created by eddi on 23. 11. 30.
//

#ifndef CLASS_TEST_DICE_H
#define CLASS_TEST_DICE_H


class Dice {
// private : 보유하고 있는 객체만 접근 할 수 있음.
private:
    const int DICE_MAX = 6;
    const int DICE_MIN = 1;
    int diceNumber;

public:
    // init_xxx_object
    Dice();

    void rollDice();
    int getDiceNumber();

    // free
    ~Dice();
};


#endif //CLASS_TEST_DICE_H
