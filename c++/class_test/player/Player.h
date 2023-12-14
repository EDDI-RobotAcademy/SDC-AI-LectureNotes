//
// Created by eddi on 23. 11. 30.
//

#ifndef CLASS_TEST_PLAYER_H
#define CLASS_TEST_PLAYER_H


#include <string>

class Player {
// set~~ 매서드를 쓰지 않고, 생성할 때 값을 지정하는게 바람직
// 외부에서 수정 될 필요가 없는 값
private:
    std::string name;
    int age;
public:
    Player(std::string&, int);
    std::string getPlayerName();
    int getPlayerAge();
    ~Player();
};


#endif //CLASS_TEST_PLAYER_H
