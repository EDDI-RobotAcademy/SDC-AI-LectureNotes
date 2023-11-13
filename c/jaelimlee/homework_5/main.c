#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "random/entity/random.h"
#include "vector/entity/vector.h"

#define MIN     -9
#define MAX     9
#define VECTORSIZE      3

int main (void)
{
    random_config();
    
    // 1. 벡터 생성
    // A_xyz 벡터 생성
    double A_xyz[VECTORSIZE];
    for (int i = 0; i < VECTORSIZE; i++)
    {
        A_xyz[i] = generate_random(MIN, MAX);
    }
    printf("A_xyw 벡터: %2f\n", A_xyz);
    
    // B_xyz 벡터 생성
    double B_xyz[VECTORSIZE];
    for (int i = 0; i < VECTORSIZE; i++)
    {
        B_xyz[i] = generate_random(MIN, MAX);
    }
    printf("B_xyw 벡터: %2f\n", B_xyz);


    // 2. 상대 벡터 
    double relative_vector[VECTORSIZE];
    for (int i = 0; i < VECTORSIZE; i++)
    {
        relative_vector[i] = B_xyz[i] - A_xyz[i];
    }
    printf("A가 B를 바라볼 때 상대벡터: %2f\n", relative_vector);

    
    // 3. 통합 벡터
    // 각 벡터의 제곱 
    double integrated_vector[VECTORSIZE];

    for (int i = 0; i < VECTORSIZE; i++)
    {
        integrated_vector[i] = pow(relative_vector[i], 2);
    }
    
    // 제곱의 합
    int integrated_vector_sum;

    for (int i = 0; i < VECTORSIZE; i++) {
        integrated_vector_sum += integrated_vector[i];
    }
    printf("통합 벡터: %d\n", (int)sqrt(integrated_vector_sum));


    return 0;
}
