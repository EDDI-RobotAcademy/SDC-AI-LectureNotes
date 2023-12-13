#include <iostream>
#include "Matrix.h"

int main() {
    Matrix *testMatrix = new Matrix();
    Matrix *transMatrix;
    Matrix *inverseMatrix;

    testMatrix->getRandom3x3Matrix();
    testMatrix->showMatrix();

    std::cout << "This is the transpose matrix!" << std::endl;
    transMatrix = testMatrix->transposeMatrix();
    transMatrix->showMatrix();

    std::cout << "This is the inverse matrix!" << std::endl;
    inverseMatrix = testMatrix->inverseMatrix();
    inverseMatrix->showMatrix2();

    return 0;
}
