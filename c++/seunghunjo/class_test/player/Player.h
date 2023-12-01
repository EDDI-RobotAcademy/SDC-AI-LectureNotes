//
// Created by eddi on 23. 11. 30.
//

#ifndef CLASS_TEST_PLAYER_H
#define CLASS_TEST_PLAYER_H


#include <string>

class Player {
private:
    // char *name - C
    // String name - Java
    std::string name;   // C++
    int age;

public:
    Player(std::string&, int);
    std::string getPlayerName();
    int getPlayerAge();
    ~Player();
};


#endif //CLASS_TEST_PLAYER_H
