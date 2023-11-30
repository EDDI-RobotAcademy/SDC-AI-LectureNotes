//
// Created by eddi on 23. 11. 30.
//

#ifndef CLASS_TEST_PLAYER_H
#define CLASS_TEST_PLAYER_H


#include <string>

class Player {
private: // extern 안한 int 같은 뭐시기, set이 아닌 생성할때 밑에 것을 집어넣으라! c랑 다르게 init 같은거 안쓰기 위함
    // char *name - C
    // String name - Java
    std::string name; // C++
    int age;

public:
    Player(std::string&, int);
    std::string getPlayName();
    int getPlayAge();

    ~Player();
};


#endif //CLASS_TEST_PLAYER_H
