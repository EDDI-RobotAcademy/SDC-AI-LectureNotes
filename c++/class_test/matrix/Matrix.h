//
// Created by eddi on 23. 11. 30.
//

#ifndef CLASS_TEST_MATRIX_H
#define CLASS_TEST_MATRIX_H


class Matrix {
private:
    const int row;
    const int column;
public:
    Matrix(int, int);
    int getMatrixRow();
    int getMatrixColumn();
    ~Matrix();
};


#endif //CLASS_TEST_MATRIX_H
