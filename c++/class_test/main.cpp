#include <iostream>
#include "dice/Dice.h"
#include "player/Player.h"
#include "vector/Vector.h"
#include "order/Order.h"
#include "post/Post.h"
#include "utility/Random_generator.h"
#include "orthogonal/Orthogonal.h"
#include "spherical/Spherical.h"
#include "utility/System_changer.h"
#include "displacement/Displacement.h"
#include "triangle/Triangle.h"


#define VECTOR_MIN  (-10)
#define VECTOR_MAX  10

int main() {
//    if(true){
//        Dice dice;
//        Dice dice2;
//    }
    // 1. 주사위 클래스를 만들어 봅시다.
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

    // 2. 사용자 클래스를 만들어 봅시다.
    delete player1;
    std::string myName = "이재승";
    int myAge = 30;
    Player player(myName, myAge);
    std::cout << "넌 이름이뭐에요??? " << player.getPlayerName() << std::endl;
    std::cout << "넌 몇살이세요???? " << player.getPlayerAge() << std::endl;



    // 3. 게시물 클래스를 만들어 봅시다.
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

    // 4. 벡터 클래스를 만들어 봅시다.

    Random_generator randomGeneratorX(VECTOR_MIN,VECTOR_MAX);
    Random_generator randomGeneratorY(VECTOR_MIN,VECTOR_MAX);
    Random_generator randomGeneratorZ(VECTOR_MIN,VECTOR_MAX);
    Random_generator _randomGeneratorX(VECTOR_MIN,VECTOR_MAX);
    Random_generator _randomGeneratorY(VECTOR_MIN,VECTOR_MAX);
    Random_generator _randomGeneratorZ(VECTOR_MIN,VECTOR_MAX);
    int randomX = randomGeneratorX.getRandomNumber();
    int randomY = randomGeneratorY.getRandomNumber();
    int randomZ = randomGeneratorZ.getRandomNumber();
    int _randomX = _randomGeneratorX.getRandomNumber();
    int _randomY = _randomGeneratorY.getRandomNumber();
    int _randomZ = _randomGeneratorZ.getRandomNumber();
    Vector vec(randomX,randomY,randomZ);
    std::cout << "X: " << vec.getX() << " Y: " << vec.getY() << " Z: " << vec.getZ() <<
     "\n랜덤 벡터의 크기: " << vec.getVectorAmount() << std::endl;

    Vector vec2(_randomX,_randomY,_randomZ);

    Vector vec3 = vec.vectorCrossProduct(vec2);

    std::cout << "VEC3 X: " << vec3.getX() << " Y: " << vec3.getY() << " Z: " << vec3.getZ() << std::endl;



    // 5. 행렬 클래스를 만들어 봅시다.


    // 6. 주문 클래스를 만들어 봅시다.
    std::vector<std::string> menu = {"abc초코", "제육볶음", "오뎅탕", "참이슬", "테라", "떡볶이", "짬뽕"};
    Order order(0);

    order.addMenu(menu);
    order.printMenu();

    // 7. 직교 좌표 클래스를 만들어 봅시다
    System_changer *systemChanger = new System_changer();

    Orthogonal *orthogonal = new Orthogonal(vec);
    Vector newVec = systemChanger->getVectorFromOrthogonal(*orthogonal);
    std::cout << "X: " << newVec.getX() << " Y: " << newVec.getY()  << " Z: " << newVec.getZ()  <<
              "\n랜덤 벡터의 크기: " << newVec.getVectorAmount() << std::endl;



    // 8. 구면 좌표 클래스를 만들어 봅시다
    Spherical spherical = systemChanger->getSphericalFromOrthogonal(*orthogonal);
    std::cout << "구면좌표 R: " << spherical.getR() << " Theta: " << spherical.getTheta()
        << " Phi: " << spherical.getPhi()  <<std::endl;
    Orthogonal ortho = systemChanger->getOrthogonalFromSpherical(spherical);
    std::cout << "직교 X: " << ortho.getX() << " Y: " << ortho.getY()
        << " Z: " << ortho.getZ()  << std::endl;

    // 9. 변위 클래스를 만들어 봅시다

    Displacement *displacement = new Displacement(vec, vec2);
    std::cout << "변위량: " << displacement->getSizeofDisplacement() << std::endl;

    free(displacement);

    // 10. 삼각형 클래스를 만들어 봅시다.

    Triangle *triangleSSS = new Triangle(10,10,12);
    triangleSSS->printTriangleSides();
    Triangle *triangleSAS = new Triangle();
    triangleSAS->getTriangleFromSAS(10,45,18);
    Triangle *triangleASA = new Triangle();
    triangleASA->getTriangleFromASA(56,10,48);


    delete(systemChanger);
    delete(orthogonal);
    delete(triangleSSS);
    delete(triangleSAS);
    delete(triangleASA);
    return 0;
}
