#include <iostream>
#include "dice/Dice.h"
#include "player/Player.h"
#include "post/Post.h"
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
        ", 나이: " << player->getPlayerAge() << std::endl;

    delete player;
    std::string post_user = "리빵준";
    std::string post_title = "속보 대한민국 전국민 탈모증세 보여";
    std::string post_content = "손흥민의 플레이에서 '헤어'나올 수 없어...";
    Post *post =new Post(1,post_user,post_title,post_content);
    std::cout << "게시글 정보 - 번호: " << post->getPostNumber()
              << ", 사용자: " << post->getPostUserName()
              << ", 제목: " << post->getPostTitle()
              << ", 내용: " << post->getPostContent()
              << std::endl;
    delete post;
    Vector *vector=new Vector();
    std::cout <<"현재 벡터 값"
              <<vector->getxVector()<<" "
              <<vector->getyVector()<<" "
              <<vector->getzVector()
              <<std::endl;
    vector->plusxVector();
    vector->plusyVector();
    vector->pluszVector();
    std::cout <<"더하기 후벡터 값"
              <<vector->getxVector()<<" "
              <<vector->getyVector()<<" "
              <<vector->getzVector()
              <<std::endl;
    delete vector;

    return 0;
}
