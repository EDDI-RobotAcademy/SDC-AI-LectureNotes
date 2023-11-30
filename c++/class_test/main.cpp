#include <iostream>
#include "dice/Dice.h"
#include "player/Player.h"
#include "vector/Vector.h"
#include "order/Order.h"
#include "post/Post.h"

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

    std::string title = "ㅇㅇㅇㅇㅇ";
    std::string writer = "ㄴㄴㄴㄴㄴㄴ";
    std::string password = "ㅁㅁㅁㅁ";
    std::string content = "ㅋㅋㅋㅋㅋㅋㅋㅋ";


    Post post(title,writer,password,content);
    post.readPost();
    if(post.checkPassword(password))
    {
        std::string n_title = "얄라리얄라";
        std::string n_content = "살어리 살어리랏다";

        post.editPost(n_title, n_content);
    }

    post.readPost();

    std::vector<std::string> menu = {"abc", "제육볶음", "오뎅탕", "참이슬", "테라", "떡볶이", "짬뽕"};
    Order order(0);

    order.addMenu(menu);
    order.printMenu();

    return 0;
}
