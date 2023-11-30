#include <iostream>
#include "01_Dice/Dice.h"
#include "02_Player/Player.h"
#include "03_Post/Post.h"

int main() {
    Dice *dice = new Dice();
    dice->rollDice();
    std::cout<< "주사위 값은 : " << dice->getDiceNumber() << std::endl;

    delete dice;

    std::string test_name1 = "조운";
    Player *player_1 = new Player(test_name1, 1);
    std::string test_name2 = "황충";
    Player *player_2 = new Player(test_name2, 2);

    std::cout << "사용자 정보 - 이름:  " << player_1->getPlayerName() <<
              ", 나이: "<< player_1->getPlayerNumber() << std::endl;
    std::cout << "사용자 정보 - 이름:  " << player_2->getPlayerName() <<
              ", 나이: "<< player_2->getPlayerNumber() << std::endl;
    delete player_1;
    delete player_2;

    std::string test_title = "삼국지";
    std::string test_writer = "나관중";
    std::string test_content = "유비좋아";

    Post *post = new Post(test_title,test_writer,test_content);
    std::cout <<"제목 : " << post->title()<<
                " 작성자 : "<< post->writer()<<
                " 내용 : "<< post->content()<< std::endl;

    delete post;

    return 0;
}
