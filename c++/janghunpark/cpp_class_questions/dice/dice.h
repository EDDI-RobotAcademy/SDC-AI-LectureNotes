//
// Created by eddi on 23. 11. 30.
//

#ifndef CPP_CLASS_QUESTIONS_DICE_H
#define CPP_CLASS_QUESTIONS_DICE_H


class dice {
private:
    const int DICE_MAX = 6;
    const int DICE_MIN = 1;
    int diceNumber;

public:
    dice();
    void rollDice();
    int getDiceNumber();
    ~dice();
};


#endif //CPP_CLASS_QUESTIONS_DICE_H
