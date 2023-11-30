//
// Created by eddi on 23. 11. 30.
//

#ifndef CPP_CLASS_QUESTIONS_ARRAY_H
#define CPP_CLASS_QUESTIONS_ARRAY_H


class Array {
private:
    const int MAX_VALUE = 9;
    const int MIN_VALUE = -9;
    int arr[2][2];

public:
    Array();
    void getRandomArray();
    int getArrayValue(int a, int b, Array *array);
    ~Array();
};


#endif //CPP_CLASS_QUESTIONS_ARRAY_H
