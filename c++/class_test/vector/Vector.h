//
// Created by eddi on 23. 11. 30.
//

#ifndef CLASS_TEST_VECTOR_H
#define CLASS_TEST_VECTOR_H


class Vector {
private:
    const int x;
    const int y;
    const int z;
public:
    Vector(int, int, int);
    float getVectorAmount();
    int getX();
    int getY();
    int getZ();
    ~Vector();

};


#endif //CLASS_TEST_VECTOR_H
