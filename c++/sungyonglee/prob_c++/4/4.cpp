//
// Created by eddi on 23. 11. 30.
//

// 4. 벡터 클래스를 만들어 봅시다.


#include <array>
#include <iostream>
#include <vector>
#include "4.h"

std::vector<int> vector_a = {1,3,5};
std::vector<int> vector_b = {2,4,6};

std::vector<int> result = addVectors(vector_a, vector_b);

Vector::Vector() {
    std::cout << vector_a << std::endl;


}



/*

#include <random>
#include <iostream>
#include "4.h"



void Vector::rollVector(){
    std::random_device rand_device;
    std::mt19937 mersenneTwister(rand_device());
    std::uniform_int_distribution<int> distribution(VECTOR_MIN, VECTOR_MAX);

     = distribution(mersenneTwister);
}
int Vector::getVectorSize(){
    std::array<int, 3> tmp_vector;
    for (int i=0; i < 3; i++){
    tmp_vector[i] = distribution(mersenneTwister);
    }
    std::cout << "벡터 : " << tmp_vector << endl;

    return tmp_vector;

}
Vector::~Vector(){

}
 */