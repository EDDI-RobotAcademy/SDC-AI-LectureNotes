#include "vector.h"

// 벡터 출력 함수
void printVector(double vector[VECTORSIZE])
{
    for (int i = 0; i < VECTORSIZE; i++)
    {
        printf("%2f", vector[i]);
    }
    return 0;
}
