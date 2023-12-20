//
// Created by eddi on 23. 12. 1.
//

#ifndef FIRST_PROBS_MATRIX_H
#define FIRST_PROBS_MATRIX_H

#include <iostream>
#include <vector>

class Matrix {

private:
    int rows, cols;
    // std::vector = *
    // std::vector<std::vector> = **
    std::vector<std::vector<double>> data;

public:
    Matrix(int rows, int cols);
    ~Matrix();

    Matrix(const Matrix& other);
    Matrix& operator=(const Matrix& other);
    Matrix operator+(const Matrix& other) const;
    Matrix operator-(const Matrix& other) const;
    std::vector<double> operator*(const std::vector<double>& vec) const;
    Matrix operator*(const Matrix& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Matrix& mat);
};

#endif //FIRST_PROBS_MATRIX_H
