#include <iostream>
#include "dice/Dice.h"

int main() {
//    if (true) {
//        Dice dice;
//        Dice dice2;
//    }

    Dice *dice = new Dice();
    dice->rollDice();

    std::cout << "얼마 나옴 ? " << dice->getDiceNumber() << std::endl;

    // 포인터로 객체 받았을 경우 delete가 필요함
    delete dice;

    return 0;
}
