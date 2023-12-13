#include <iostream>
#include "1dice/Dice.h"
#include "2player/Player.h"
#include "3board/Board.h"
#include "4vector/Vector.h"

int main() {
    // 다이스
    Dice *dice = new Dice();
    dice->rollDice();
    std::string  test_post = "나는 빡빡이다";
    std::string  test_name = "윤상근";
    std::string  test_title = "밥선생님";
    std::cout << "결과는? " << dice->getDiceNumber() << std::endl;

    delete dice;

    // 플레이어
    Player *player = new Player(test_name, 29);

    std::cout << "사용자 정보 - 이름 " << player->getPlayerName() <<
        ", 나이: " << player->getPlayerAge() << std::endl;

    // 보드
    Board *board = new Board(test_name,test_post,test_title);

    std::cout << "Board tile " << board->title() <<
              ", : name " << board->name() <<
              ", : post " << board->post() <<std::endl;
    // 벡터
    Vector *vector1 = new Vector();
    Vector *vector2 = new Vector();
    Vector *add_Vector = new Vector();
    Vector *sub_Vector = new Vector();
    vector1->rollVector();
    vector2->rollVector();
    add_Vector->addVector(*vector1, *vector2);
    sub_Vector->subVector(*vector1, *vector2);


    std::cout << "1번 X 결과!! " << vector1->getVectorX() << " , Y 결과!! "<< vector1->getVectorY()
    << " , Z 결과!! "<< vector1->getVectorZ() << std::endl;

    std::cout << "2번 X 결과!! " << vector2->getVectorX() << " , Y 결과!! "<< vector2->getVectorY()
              << " , Z 결과!! "<< vector2->getVectorZ() << std::endl;

    std::cout << "-----------------------------------------" << std::endl;

    std::cout << "X 합!! " << add_Vector->getVectorX() << " , Y 합!! "<< add_Vector->getVectorY()
              << " , Z 합!! "<< add_Vector->getVectorZ() << std::endl;

    std::cout << "X 빼!! " << sub_Vector->getVectorX() << " , Y 빼!! "<< sub_Vector->getVectorY()
              << " , Z 빼!! "<< sub_Vector->getVectorZ() << std::endl;
    delete vector1;
    delete vector2;


    // 행렬

    for(int i=0;i<2;++i){
        for(int j=0;j<2;++j){
            std:: << C[i][j] <<" ";
        }
        std::cout<<"/n";
    }
    return 0;
}
