//
// Created by eddi on 23. 11. 30.
//

#ifndef CPP_CLASS_QUESTIONS_VECTOR_H
#define CPP_CLASS_QUESTIONS_VECTOR_H


class Vector {
private:
    const int MAX_VALUE = 9;
    const int MIN_VALUE = -9;
    int x;
    int y;
    int z;
public:
    Vector();
    void getRandomValue();
    int getVectorXValue();
    int getVectorYValue();
    int getVectorZValue();
    Vector *addVector(Vector *final, Vector *a, Vector *b);
//    Vector *radianAngle(Vector *a, Vector *b);
    ~Vector();
};


#endif //CPP_CLASS_QUESTIONS_VECTOR_H
