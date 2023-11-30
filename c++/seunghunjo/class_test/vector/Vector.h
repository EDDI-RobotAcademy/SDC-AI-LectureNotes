//
// Created by eddi on 23. 11. 30.
//

#ifndef CLASS_TEST_VECTOR_H
#define CLASS_TEST_VECTOR_H


class Vector {
private:
    const int VECTOR_MAX = 10;
    const int VECTOR_MIN = 0;
    int x;
    int y;
    int z;

public:
    Vector();
    int randomOperation();
    void vectorRandomResponse();
    void vectorAdd(Vector, Vector);
    void vectorSub(Vector, Vector);
    ~Vector();
};


#endif //CLASS_TEST_VECTOR_H
