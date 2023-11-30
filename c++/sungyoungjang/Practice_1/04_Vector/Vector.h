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
    int randomNumber;
public:
    Vector();
    Vector(int x,int y, int z);

    void VectorRandom();
    int getVectorRandomNum();
    static Vector VectorAdd(const Vector& v1, const Vector& v2);
    static Vector VectorSub(const Vector& v1, const Vector& v2);
    ~Vector();

};


#endif //PRACTICE_1_VECTOR_H
