//
// Created by eddi on 23. 11. 30.
//

#ifndef PRACTICE_1_VECTOR_H
#define PRACTICE_1_VECTOR_H


class Vector {
private:
    const int MAX_NUM = 10;
    const int MIN_NUM = 1;
    int x;
    int y;
    int z;
public:
    Vector();
    void VectorRandom();
    void VectorAdd(Vector,Vector);
    void VectorSub(Vector, Vector);
    int getVectorX();
    int getVectorY();
    int getVectorZ();



};


#endif //PRACTICE_1_VECTOR_H
