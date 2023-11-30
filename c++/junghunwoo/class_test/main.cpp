#include <iostream>
#include "dice/Dice.h"
#include "player/Player.h"
#include "post/Post.h"

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
              ", 나이: " << player->getPlayerAge() << std::endl;

    delete player;

    std::string test_title = "제목";
    std::string test_writer = "작성자";
    std::string test_content = "내용";
    Post *post = new Post(1, test_title, test_writer, test_content);
    std::cout << "게시물 번호 : "<< post->getid() << ", 제목 : " << post->gettitle() << ", 작성자 : " << post->getwriter()
                << ", 내용 : " << post->getcontent() << std::endl;

    delete post;

    return 0;
}