//
// Created by eddi on 23. 12. 1.
//

#ifndef PROB_C___5_H
#define PROB_C___5_H

#include <vector>

class Matrix {
private:
    std::vector<int> m_Data;
    int m_Row = 0, m_Column = 0;

public:
    Matrix() noexcept = default;
    Matrix(int row, int column);
    Matrix(int value, int row, int column);
    Matrix(std::vector<int> data, int row, int column);
    Matrix(const Matrix& matrix);
    Matrix(Matrix&& matrix) noexcept;
    ~Matrix();
};

#endif //PROB_C___5_H
