#include <iostream>
#include "dice/Dice.h"
#include "player/Player.h"
#include "vector/Vector.h"
#include "order/Order.h"

int main() {
//    if(true){
//        Dice dice;
//        Dice dice2;
//    }

    Dice *dice = new Dice();
    dice->rollDice();

    std::cout << "얼마 나옴?" << dice->getDiceNumber() << std::endl;

    // 포인터로 객체를 받았을 경우 delete가 필요함
    delete dice;

    Dice dice1;
    dice1.rollDice();
    std::cout << "이것도 됨??" << dice1.getDiceNumber() << std::endl;

    std::string test_name = "테스트";
    Player *player1 = new Player(test_name, 20);
    std::cout << "이름이뭐에요??? " << player1->getPlayerName() <<
    "\n몇살이세요???? " << player1->getPlayerAge() << std::endl;


    delete player1;
    std::string myName = "이재승";
    int myAge = 30;
    Player player(myName, myAge);
    std::cout << "넌 이름이뭐에요??? " << player.getPlayerName() << std::endl;
    std::cout << "넌 몇살이세요???? " << player.getPlayerAge() << std::endl;



    return 0;
}
