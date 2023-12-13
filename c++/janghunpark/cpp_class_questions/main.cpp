#include <iostream>
#include "dice/dice.h"
#include "player/Player.h"
#include "board/Board.h"
#include "vector/Vector.h"
#include "array/Array.h"
#include "order/Order.h"
#include "Cartesian/Cartesian.h"

int main() {

    // Q1. 주사위 클래스
    std::cout << "1번 문제" << std::endl;
    dice *Dice = new dice();
    Dice->rollDice();
    std::cout << "First Dice Number = " << Dice->getDiceNumber() << std::endl;
    dice Dice2;
    Dice2.rollDice();
    std::cout << "Second Dice Number = " << Dice2.getDiceNumber() << std::endl; // no malloc
    delete Dice;

    // Q2. 사용자 클래스
    std::cout << "\n2번 문제" << std::endl;
    std::string testName = "철수";
    Player *player = new Player(testName, 20);
    std::cout << "사용자 정보\n이름: " << player->getPlayerName() << ", 나이: " << player->getPlayerAge() << std::endl;
    delete player;

    // Q3. 게시물 클래스
    std::cout << "\n3번 문제" << std::endl;
    unsigned int testId = 0;
    std::string testTitle = "이거슨 젬옥";
    std::string testWriter = "요고슨 작승자";
    std::string testContent = "마! 내가 내용이다!";
    Board *testBoard = new Board(testId, testTitle, testWriter, testContent);
    std::cout << "This is Board!\nBoard Id: " << testBoard->getBoardNumber()
                << "\nTitle: " << testBoard->getBoardTitle() << "\nWriter: " << testBoard->getBoardWriter()
                << "\nContent: " << testBoard->getBoardContent() << std::endl;
    delete testBoard;

    // Q4. 벡터 클래스
    std::cout << "\n4번 문제" << std::endl;
    Vector *vectorA = new Vector();
    Vector *vectorB = new Vector();
    Vector *finalVector = new Vector();
    vectorA->getRandomValue();
    vectorB->getRandomValue();
    std::cout << "A Vector Values\nx = " << vectorA->getVectorXValue() << "\ny = "
                << vectorA->getVectorYValue() << "\nz = " << vectorA->getVectorZValue() << std::endl;
    std::cout << "B Vector Values\nx = " << vectorB->getVectorXValue() << "\ny = "
              << vectorB->getVectorYValue() << "\nz = " << vectorB->getVectorZValue() << std::endl;
    finalVector->addVector(finalVector, vectorA, vectorB);
    std::cout << "Final Vector Values\nx = " << finalVector->getVectorXValue() << "\ny = "
              << finalVector->getVectorYValue() << "\nz = " << finalVector->getVectorZValue() << std::endl;
    delete vectorA;
    delete vectorB;
    delete finalVector;

    // Q5. 행렬 클래스
    std::cout << "\n5번 문제" << std::endl;
    Array *array = new Array();
    array->getRandomArray();
    std::cout << "What is the value in the array[0][0]? " << array->getArrayValue(0, 0, array) << std::endl;
    std::cout << "What is the value in the array[0][1]? " << array->getArrayValue(0, 1, array) << std::endl;
    std::cout << "What is the value in the array[1][0]? " << array->getArrayValue(1, 0, array) << std::endl;
    std::cout << "What is the value in the array[1][1]? " << array->getArrayValue(1, 1, array) << std::endl;
    delete array;

    // Q6. 주문 클래스
    std::cout << "\n6번 문제" << std::endl;
    Order *testOrder = new Order();
    std::string testPlayerName = "영희";
    Player *testPlayer = new Player(testPlayerName, 15);
    testOrder->setCommandWithPlayer(testPlayer, testOrder->getRandomCommand());
    delete testPlayer;
    delete testOrder;

    // Q7. 직교 좌표계 클래스
    std::cout << "\n7번 문제" << std::endl;
    float length;
    Cartesian *testCartesian1 = new Cartesian();
    Cartesian *testCartesian2 = new Cartesian();
    testCartesian1->setCartesianCoordinate(2.1, -5.3);
    testCartesian2->setCartesianCoordinate(4.9, 1.7);
//    length = lengthBetweenTwoPoint(testCartesian1, testCartesian2);

    return 0;
}
