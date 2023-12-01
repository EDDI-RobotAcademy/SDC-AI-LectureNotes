//
// Created by eddi on 23. 11. 30.
//

#ifndef CLASS_TEST_VECTOR_H
#define CLASS_TEST_VECTOR_H


#include <string>


class Vector {
private:
    static const int VECTOR_MAX = 10;
    static const int VECTOR_MIN = 0;

    std::string vectorName;
    int vectorX;
    int vectorY;
    int vectorZ;


public:
    Vector(std::string&, int, int, int);
    std::string getVectorName();
    void randomVectorValue();
    int getVectorX();
    int getVectorY();
    int getVectorZ();
    int vectorSum(const Vector& other);
    int vectorCrossProduct(const Vector& other) const;
    int vectorScalarProduct(const Vector&, int amount);
    ~Vector();

};


#endif //CLASS_TEST_VECTOR_H
