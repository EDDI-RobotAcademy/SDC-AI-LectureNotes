//
// Created by eddi on 23. 12. 1.
//

#include <random>
#include "Random_generator.h"

Random_generator::Random_generator(int _min, int _max) {

    // 아래 방식은 C++에서 권장하는 새로운 방식의 랜덤 생성 방법론입니다.
    // 메르센 트위스터 알고리즘에 대해 파악하려고하지 말고
    // '아 이렇게 작성하는구나' 하고 넘깁시다.
    // 만약 이것을 파고 싶다면 수학과로 갑시다.
    std::random_device rand_device;
    std::mt19937 mersenneTwister(rand_device());
    std::uniform_int_distribution<int> distribution(_min, _max);
    randomNumber = distribution(mersenneTwister);
}

int Random_generator::getRandomNumber() {
    return randomNumber;
}

Random_generator::~Random_generator() {

}
