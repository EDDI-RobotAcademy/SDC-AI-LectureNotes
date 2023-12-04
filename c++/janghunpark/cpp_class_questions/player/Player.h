//
// Created by eddi on 23. 11. 30.
//

#ifndef CPP_CLASS_QUESTIONS_PLAYER_H
#define CPP_CLASS_QUESTIONS_PLAYER_H

#include <string>

class Player {
private:
    std::string name;
    int age;

public:
    Player(std::string&, int);
    std::string getPlayerName();
    int getPlayerAge();
    ~Player();
};


#endif //CPP_CLASS_QUESTIONS_PLAYER_H
