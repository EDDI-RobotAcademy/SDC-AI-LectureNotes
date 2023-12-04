#include <stdio.h>
#include <math.h>
#include "random.h"
#include "vector.h"

// 과제
// x, y, z 벡터가 존재
// A_xyz 벡터에 -9 ~ 9 사이의 임의의 크기를 줌
// B_xyz 벡터에 -9 ~ 9 사이의 임의의 크기를 줌
// 통합 벡터는 x, y, z 각각의 벡터의 계산으로 산출
// A가 B를 바라 볼 때 상대 벡터를 출력
// 통합 벡터 길이 = sqrt(x^2 + y^2 + z^2) 

int main(void)
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
