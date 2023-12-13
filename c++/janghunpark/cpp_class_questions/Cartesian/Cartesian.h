//
// Created by eddi on 23. 12. 1.
//

#ifndef CPP_CLASS_QUESTIONS_CARTESIAN_H
#define CPP_CLASS_QUESTIONS_CARTESIAN_H


class Cartesian {
private:
//    const int MIN_VALUE = -99;
//    const int MAX_VALUE = 99;
    float xValue;
    float yValue;
public:
    Cartesian();
//    void getRandomCartesianCoordinate();
    void setCartesianCoordinate(float num1, float num2);
    ~Cartesian();
};
//float lengthBetweenTwoPoint(Cartesian *coordinate1, Cartesian *coordinate2);

#endif //CPP_CLASS_QUESTIONS_CARTESIAN_H
