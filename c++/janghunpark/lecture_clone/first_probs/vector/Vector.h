//
// Created by eddi on 23. 12. 1.
//

#ifndef FIRST_PROBS_VECTOR_H
#define FIRST_PROBS_VECTOR_H


#include <ostream>
#include "../utility/RandomGenerator.h"

// 결론 class를 사용 할 때는
// 내부 정보 변경은 반드시 매서드(함수)를 통해서 진행합니다.
class Vector {
private:
    float x, y, z;

public:
    Vector(float x = RandomGenerator::generate(),
           float y = RandomGenerator::generate(),
           float z = RandomGenerator::generate());
    float getX();
    float getY();
    float getZ();
    Vector operator+(const Vector& other) const;
    Vector operator-(const Vector& other);
    friend std::ostream& operator<<(std::ostream& os, const Vector& vec);
    ~Vector();
};


#endif //FIRST_PROBS_VECTOR_H
