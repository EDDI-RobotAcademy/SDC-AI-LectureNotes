//
// Created by eddi on 23. 11. 30.
//

#include "Dice.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include "../utility/Random_generator.h"

Dice::Dice() {
    std::cout << "생성자입니다" << std::endl;

    // 지금 보았듯이 다소 이상한 랜덤을 생성하는 것을 볼 수 있다.
    //srand(static_cast<unsigned int>(time(0)));
}

void Dice::rollDice() {
    //diceNumber = rand()%(DICE_MAX - DICE_MIN + 1) +DICE_MIN;

    // 아래 방식은 C++에서 권장하는 새로운 방식의 랜덤 생성 방법론입니다.
    // 메르센 트위스터 알고리즘에 대해 파악하려고하지 말고
    // '아 이렇게 작성하는구나' 하고 넘깁시다.
    // 만약 이것을 파고 싶다면 수학과로 갑시다.
//    std::random_device rand_device;
//    std::mt19937 mersenneTwister(rand_device());
//    std::uniform_int_distribution<int> distribution(DICE_MIN, DICE_MAX);
//
//    diceNumber = distribution(mersenneTwister);

    Random_generator randomGenerator(DICE_MIN,DICE_MAX);
    diceNumber = randomGenerator.getRandomNumber();
}

int Dice::getDiceNumber() {
    return diceNumber;
}

Dice::~Dice() {
    std::cout << "~소멸자입니다!" << std::endl;
}