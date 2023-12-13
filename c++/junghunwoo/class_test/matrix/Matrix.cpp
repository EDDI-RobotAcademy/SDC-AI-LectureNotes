#include "Matrix.h"
#include <vector>
#include <iostream>
#include <iomanip>

Matrix::Matrix(int max_row, int max_col) : max_row(max_row), max_col(max_col){ }

void Matrix::setmatrix() {
    std::vector <std::vector<int>> row(max_row, std::vector<int>(max_col));
    std::vector <int> col;



    int i, j, n;
    int max_number;
    max_number = max_col * max_row;

    for (i = 0; i < max_row; ++i) {

        for (j = 0; j < max_col; ++j) {
            for (n = 0; n < max_number; ++n){
                row[i][j] = n;
            }
        }
    }

    for (i = 0; i < max_row; ++i) {
        for (j = 0; j < max_col; ++j) {
            std::cout << std::setw(5) << row[i][j];
        }
        std::cout << std::endl;
    }
}

Matrix::~Matrix(){ }
