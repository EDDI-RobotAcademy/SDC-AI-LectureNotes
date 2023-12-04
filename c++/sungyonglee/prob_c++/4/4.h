//
// Created by eddi on 23. 11. 30.
//

#ifndef PROB_C___4_H
#define PROB_C___4_H

class Vector {
private:
    const int VECTOR_MAX = 10;
    const int VECTOR_MIN = 0;
    int x;
    int y;
    int z;

public:
    void rollVector();
    Vector();
    int getX();
    int getY();
    int getZ();
    void sumVector(Vector, Vector);
    void subVector(Vector, Vector);
    ~Vector();
};

#endif //PROB_C___4_H
