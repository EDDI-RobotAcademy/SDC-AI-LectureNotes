#include <iostream>
#include "01_Dice/Dice.h"
#include "02_Player/Player.h"
#include "03_Post/Post.h"
#include "04_Vector/Vector.h"

int main() {
    //1번 다이스
    Dice *dice = new Dice();
    dice->rollDice();
    std::cout<< "주사위 값은 : " << dice->getDiceNumber() << std::endl;

    delete dice;
    //2번 플레이어
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

    //3번 게시글
    std::string test_title = "삼국지";
    std::string test_writer = "나관중";
    std::string test_content = "유비좋아";

    Post *post = new Post(test_title,test_writer,test_content);
    std::cout <<"제목  : " << post->title()<<
                "\n작성자 : "<< post->writer()<<
                "\n내용  : "<< post->content()<< std::endl;

    delete post;
    //4번 벡터
    Vector *vector1 = new Vector();
    Vector *vector2 = new Vector();

    vector1->VectorRandom();
    vector2->VectorRandom();

    std::cout<<"vector 1 x값 : " <<vector1->getVectorX()<<
             "\nvector 1 y값 : " <<vector1->getVectorY()<<
             "\nvector 1 z값 : " <<vector1->getVectorZ()<< std::endl;
    std::cout<<"\nvector 2 x값 : " <<vector2->getVectorX()<<
             "\nvector 2 y값 : " <<vector2->getVectorY()<<
             "\nvector 2 z값 : " <<vector2->getVectorZ()<< std::endl;
    Vector *addVector = new Vector();
    Vector *subVector = new Vector();

   addVector->VectorAdd(*vector1,*vector2);
   subVector->VectorSub(*vector1,*vector2);
   std::cout<<"\nvector 1+2"
            <<"\nvector  x값 : " <<addVector->getVectorX()<<
            "\nvector  y값 : " <<addVector->getVectorY()<<
            "\nvector  z값 : " <<addVector->getVectorZ()<< std::endl;

    std::cout<<"\nvector 1-2"
            <<"\nvector  x값 : " <<subVector->getVectorX()<<
             "\nvector  y값 : " <<subVector->getVectorY()<<
             "\nvector  z값 : " <<subVector->getVectorZ()<< std::endl;

    delete vector1;
    delete vector2;
    delete addVector;
    delete subVector;

    //5번 행렬

    }










