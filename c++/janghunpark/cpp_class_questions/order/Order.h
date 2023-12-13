//
// Created by eddi on 23. 11. 30.
//

#ifndef CPP_CLASS_QUESTIONS_ORDER_H
#define CPP_CLASS_QUESTIONS_ORDER_H

#include "../player/Player.h"

class Order {
private:
    int commandNumber;
    Player *player;
public:
    Order();
    int getRandomCommand();
    void setCommandWithPlayer(Player *, int);
    ~Order();
};


#endif //CPP_CLASS_QUESTIONS_ORDER_H
