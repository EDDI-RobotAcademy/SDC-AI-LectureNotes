//
// Created by eddi on 23. 11. 30.
//

#ifndef CLASS_TEST_PLAYER_H
#define CLASS_TEST_PLAYER_H


#include <string>

class Player {

private: // exturn을 하지 않았다고 보면 됨 = ?, 반드시 생성자 메소드를 이용해야함
    // string 이 char * 를 대체해줌
    // String name -JAVA
    // char *name - C
    std::string name; // C++
    int age;

public: // C에서 소스에 있는 함수 이름 넣는 것과 동일
    Player(std::string&, int); // &는 레퍼런스, * 포인터와 같음
    std::string getPlayerName();
    int getPlayerAge();
    ~Player();
};


#endif //CLASS_TEST_PLAYER_H
