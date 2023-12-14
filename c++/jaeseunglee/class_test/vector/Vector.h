//
// Created by eddi on 23. 11. 30.
//

#ifndef CLASS_TEST_VECTOR_H
#define CLASS_TEST_VECTOR_H


class Vector {
private:
    int x;
    int y;
    int z;
public:
    Vector(int, int, int);
    Vector vectorSum(Vector&);
    Vector vectorScalarProduct(int);
    Vector vectorCrossProduct(Vector&);
    float getVectorAmount();
    int getX();
    int getY();
    int getZ();
    ~Vector();

};


#endif //CLASS_TEST_VECTOR_H
