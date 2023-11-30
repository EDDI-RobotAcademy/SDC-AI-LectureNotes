//
// Created by eddi on 23. 11. 30.
//

#ifndef CLASS_TEST_VECTOR_H
#define CLASS_TEST_VECTOR_H


class Vector {
private:
    const int VECTOR_MAX = 6;
    const int VECTOR_MIN = 1;
    int x;
    int y;
    int z;

public:
    Vector();
    void randomx();
    void randomy();
    void randomz();
    int getvector(int, int, int);
    ~Vector();
};


#endif //CLASS_TEST_VECTOR_H