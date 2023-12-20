//
// Created by eddi on 23. 12. 1.
//

#include "Matrix.h"
#include "../utility/RandomGenerator.h"

Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols), data(rows, std::vector<double>(cols, 0.0)) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            data[i][j] = RandomGenerator::generate();
        }
    }
}

Matrix::~Matrix() {}

Matrix::Matrix(const Matrix& other) : rows(other.rows), cols(other.cols), data(other.data) {}

// copy의 개념
Matrix& Matrix::operator=(const Matrix& other) {
    if (this != &other) {
        rows = other.rows;
        cols = other.cols;
        data = other.data;
    }
    return *this;
}

Matrix Matrix::operator+(const Matrix& other) const {
    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            //result.data[i][j] = data[i][j] + other.data[i][j];
            result.data[i][j] = this->data[i][j] + other.data[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator-(const Matrix& other) const {
    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.data[i][j] = data[i][j] - other.data[i][j];
        }
    }
    return result;
}

std::vector<double> Matrix::operator*(const std::vector<double>& vec) const {
    std::vector<double> result(rows, 0.0);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i] += data[i][j] * vec[j];
        }
    }
    return result;
}

Matrix Matrix::operator*(const Matrix& other) const {
    Matrix result(rows, other.cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < other.cols; ++j) {
            for (int k = 0; k < cols; ++k) {
                result.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }
    return result;
}

std::ostream& operator<<(std::ostream& os, const Matrix& mat) {
    for (int i = 0; i < mat.rows; ++i) {
        for (int j = 0; j < mat.cols; ++j) {
            os << mat.data[i][j] << ' ';
        }
        os << '\n';
    }
    return os;
}
