//
// Created by eddi on 23. 11. 30.
//
/*
#ifndef CLASS_TEST_VECTOR_H
#define CLASS_TEST_VECTOR_H

#include <vector>

class Vector {
private:
    std::vector<int> x;
    int y;
    int z;
    const int VECTOR_MAX = 6;
    const int VECTOR_MIN = 1;

public:
    Vector();
    void randomx();
    void randomy();
    void randomz();
    int printvector();
    ~Vector();
};


#endif //CLASS_TEST_VECTOR_H