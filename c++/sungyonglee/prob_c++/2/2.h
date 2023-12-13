//
// Created by eddi on 23. 11. 30.
//

#ifndef PROB_C___2_H
#define PROB_C___2_H

#include <string>

class Player {
private:
    std::string name;
    int age;
    int height;

public:
    Player(std::string&, int, int);
    std::string getPlayerName();
    int getPlayerAge();
    int getPlayerHeight();
    ~Player();
};

#endif //PROB_C___2_H
