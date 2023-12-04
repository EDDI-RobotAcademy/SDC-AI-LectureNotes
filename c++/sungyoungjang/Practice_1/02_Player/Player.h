//
// Created by eddi on 23. 11. 30.
//

#ifndef PRACTICE_1_PLAYER_H
#define PRACTICE_1_PLAYER_H


#include <string>

class Player {
private:
    std::string name;
    int PlayerNumber;

public:
    Player(std::string&, int);
    std::string getPlayerName();
    int getPlayerNumber();
    ~Player();

};


#endif //PRACTICE_1_PLAYER_H
