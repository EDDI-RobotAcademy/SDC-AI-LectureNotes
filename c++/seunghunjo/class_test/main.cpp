#include <iostream>
#include "dice/Dice.h"
#include "player/Player.h"
#include "vector/Vector.h"

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

    Dice dice2;
    dice2.rollDice();

    std::cout << "이것도 됨 ? " << dice2.getDiceNumber() << std::endl;

    std::string test_name = "테스트";
    Player *player = new Player(test_name, 20);

    std::cout << "사용자 정보 - 이름: " << player->getPlayerName() <<
        ", 나이: "<< player->getPlayerAge() << std::endl;

    delete player;



    return 0;
}