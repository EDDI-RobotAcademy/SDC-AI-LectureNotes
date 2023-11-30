#include <iostream>
#include "dice/Dice.h"
#include "player/Player.h"
#include "board/Board.h"
#include "vector/Vector.h"

int main() {
//    if (true) {
//        Dice dice;
//        Dice dice2;
//    }

    // 1. 주사위 클래스를 만들어 봅시다.
    std::cout << "1번" << std::endl;
    Dice *dice = new Dice();
    dice->rollDice();

    std::cout << "얼마 나옴 ? " << dice->getDiceNumber() << std::endl;

    delete dice;

    // 포인터로 객체 받았을 경우 delete가 필요함

    Dice dice2;
    dice2.rollDice();

    std::cout << "얼마 나옴 ? " << dice2.getDiceNumber() << std::endl;


    // 2. 사용자 클래스를 만들어 봅시다.
    std::cout << "\n2번" << std::endl;
    std::string test_name1 = "테스트";
    std::string test_name2 = "테스터";
    Player *player1 = new Player(test_name1, 20);

    std::cout << "사용자 정보 - 이름: " << player1->getPlayerName() <<
    ", 나이 " << player1->getPlayerAge() << std::endl;

    Player *player2 = new Player(test_name2, 30);
    std::cout << "사용자 정보 - 이름: " << player2->getPlayerName() <<
              ", 나이 " << player2->getPlayerAge() << std::endl;

    delete player1;
    delete player2;

    // 3. 게시물 클래스를 만들어 봅시다.
    std::cout << "\n3번" << std::endl;
    std::string writer = "junghwan";
    std::string title = "C++";
    std::string contents = "존나 어렵네";
    Board *board = new Board(writer, title, contents);
    std::cout <<"게시물 작성자: " << board->getWriterLength() <<
    ", 제목: " << board->getTitleLength() <<
    ", 내용: " << board->getContentsLength() << std::endl;

    delete board;

    // 4. 벡터 클래스를 만들어 봅시다.
    std::cout << "\n4번" << std::endl;

    std::string vectorNameA = "A";
/*    int vectorAX = 0;
    int vectorAY = 0;
    int vectorAZ = 0;*/
    Vector *vectorA = new Vector(vectorNameA, 0, 0, 0);
    vectorA->randomVectorValue();

    std::cout << "vector: " << vectorA->getVectorName() <<
              ", X: " << vectorA->getVectorX() <<
              ", Y: " << vectorA->getVectorY() <<
              ", Z: " << vectorA->getVectorZ() <<std::endl;


    std::string vectorNameB = "B";
/*    int vectorBX = 0;
    int vectorBY = 0;
    int vectorBZ = 0;*/
    Vector *vectorB = new Vector(vectorNameB, 0, 0, 0);
    vectorB->randomVectorValue();

    std::cout << "vector: " << vectorB->getVectorName() <<
              ", X: " << vectorB->getVectorX() <<
              ", Y: " << vectorB->getVectorY() <<
              ", Z: " << vectorB->getVectorZ() <<std::endl;



    delete vectorA;
    delete vectorB;

// 5. 행렬 클래스를 만들어 봅시다.

    return 0;
}
