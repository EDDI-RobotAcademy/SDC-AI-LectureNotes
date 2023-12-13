//
// Created by eddi on 23. 12. 1.
//

#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H


class Matrix {
private:
    const int MIN_VALUE = -9;
    const int MAX_VALUE = 9;
    double Mat3x3[3][3];
public:
    Matrix();
    void getRandom3x3Matrix();
    void showMatrix();
    void showMatrix2();
    Matrix *transposeMatrix();
    Matrix *inverseMatrix();
    Matrix addOperation(const Matrix&);
    Matrix subOperation(const Matrix&);
    Matrix mulOperation(const Matrix&);
    ~Matrix();
};

#endif //MATRIX_MATRIX_H
