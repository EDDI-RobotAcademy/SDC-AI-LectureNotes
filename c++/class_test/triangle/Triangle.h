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
    Triangle(float, float, float);
    float getTriangleArea();
    ~Triangle();
};


#endif //CLASS_TEST_TRIANGLE_H
