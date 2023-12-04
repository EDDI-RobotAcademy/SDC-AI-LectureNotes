//
// Created by eddi on 23. 12. 1.
//

// 5. 행렬 클래스를 만들어 봅시다.

#include <cassert>
#include "5.h"

Matrix::Matrix(int row, int column)
    : m_Data(row * column), m_Row(row), m_Column(column) {
    assert((row == 0 && column == 0) || (row > 0 && column > 0));
}

Matrix::Matrix(int value, int row, int column)
    : m_Data(row * column, value), m_Row(row), m_Column(column) {
    assert((row == 0 && column == 0) || (row > 0 && column > 0));
}

Matrix::Matrix(std::vector<int> data, int row, int column)
    : m_Data(data), m_Row(row), m_Column(column) {
    assert((row == 0 && column == 0) || (row > 0 && column > 0));
    assert(row * column == m_Data.size());
}
Matrix::Matrix(const Matrix& matrix)
    : m_Data(matrix.m_Data), m_Row(matrix.m_Row), m_Column(matrix.m_Column) {
}
Matrix::Matrix(Matrix&& matrix) noexcept
    : m_Data(std::move(matrix.m_Data)), m_Row(matrix.m_Row), m_Column(matrix.m_Column) {
    matrix.m_Row = matrix.m_Column = 0;
}
Matrix::~Matrix() { }