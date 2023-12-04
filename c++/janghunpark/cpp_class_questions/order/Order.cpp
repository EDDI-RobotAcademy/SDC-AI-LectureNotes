//
// Created by eddi on 23. 11. 30.
//

#include "Order.h"

#include <iostream>

#include <random>

Order::Order() {}

int Order::getRandomCommand() {
    std::random_device rand_device;
    std::mt19937 mersenneTwister(rand_device());
    std::uniform_int_distribution<int> distribution(1, 5);

    commandNumber = distribution(mersenneTwister);

    return commandNumber;
}

void Order::setCommandWithPlayer(Player *player1, int commandNum) {
    std::cout << player1->getPlayerName() << "님이 " << commandNum << "번을 주문하셨습니다." << std::endl;
}

Order::~Order() {}