//
// Created by eddi on 23. 11. 30.
//

#ifndef CLASS_TEST_TRIANGLE_H
#define CLASS_TEST_TRIANGLE_H


class Triangle {
private:
    float side1;
    float side2;
    float side3;
public:
    Triangle();
    Triangle(float, float, float);
    void getTriangleFromSAS(float, float, float);
    void getTriangleFromASA(float, float, float);
    void printTriangleSides();
    float getTriangleArea();
    ~Triangle();
};


#endif //CLASS_TEST_TRIANGLE_H
