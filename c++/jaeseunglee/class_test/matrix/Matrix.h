//
// Created by eddi on 23. 11. 30.
//

#ifndef CLASS_TEST_MATRIX_H
#define CLASS_TEST_MATRIX_H


#include <vector>

class Matrix {
private:
    int row;
    int column;

public:
    std::vector<std::vector<int>> matrix;
    Matrix(int, int);
    Matrix(std::vector<std::vector<int>>);
    int getMatrixRow();
    int getMatrixColumn();
    void matrixSum(Matrix&);
    Matrix matrixMultiplication(Matrix&);
    ~Matrix();
};


#endif //CLASS_TEST_MATRIX_H
