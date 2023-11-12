#include <stdio.h>
#include <math.h>
#include "random.h"
#include "vector.h"


int main (void)
{
    random_config();
    
    // 1. 벡터 생성
    // A_xyz 벡터 생성
    double A_xyz[VECTORSIZE];
    for (int i = 0; i < VECTORSIZE; i++)
    {
        A_xyz[i] = generate_random(const int MIN, const int MAX);
    }
    printf("A_xyw 벡터: %2f", A_xyz);
    
    // B_xyz 벡터 생성
    double B_xyz[VECTORSIZE];
    for (int i = 0; i < VECTORSIZE; i++)
    {
        B_xyz[i] = generate_random(const int MIN, const int MAX);
    }
    printf("B_xyw 벡터: %2f", B_xyz);



    printf("sqrt(3^2 + 4^2) = %d\n", (int)sqrt(pow(3, 2) + pow(4, 2)));

    return 0;
}
