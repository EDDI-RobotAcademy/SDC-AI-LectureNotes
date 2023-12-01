#include <iostream>

#include "1/1.h"
#include "2/2.h"
#include "3/3.h"
#include "4/4.h"

int main() {
    // 1 번 문제
    Dice *dice = new Dice();
    dice->rollDice();
    std::cout << "주사위 눈금: " << dice->getDiceNumber() << std::endl;
    delete dice;

    // 2 번 문제
    std::string second_name = "시계";
    Player *player = new Player(second_name, 20, 70);

    std::cout << "2 번 문제\n사용자 정보 - 이름: " << player->getPlayerName() << ", 나이: " << player->getPlayerAge() << ", 몸무게: " << player->getPlayerHeight() << "\n" << std::endl;
    delete player;


    // 3 번 문제
    std::string post_title = "시계";
    std::string post_writer = "야옹이";
    std::string post_content = "3 시 30 분";
    Post *post = new Post(post_title, post_writer, post_content);

    std::cout << "3 번 문제\n게시물 정보 - 제목: " << post->getPostTitle() << ", 작성자: " << post->getPostWriter() << ", 내용: " << post->getPostContent()<< std::endl;
    delete post;

    // 4 번 문제

    Vector vector1;
    vector1.rollVector();

    Vector vector2;
    vector2.rollVector();

    Vector *result_vector = new Vector();
    result_vector->sumVector(vector1, vector2);

    // delete vector;

    return 0;
}
