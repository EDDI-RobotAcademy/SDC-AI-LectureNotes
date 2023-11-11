#include <stdio.h>

#include "vector/vector.h"
#include "utility/random.h"


 
// x, y, z 벡터가 존재합니다.
// A_xyz 벡터에 -9 ~ 9 사이의 임의의 크기를 줍니다.
// B_xyz 벡터에 -9 ~ 9 사이의 임의의 크기를 줍니다.
// 통합 벡터는 x, y, z 각각의 벡터의 계산으로 산출합니다.
// A가 B를 바라 볼 때 상대 벡터를 출력하세요.
// 통합 벡터 길이 = sqrt(x^2 + y^2 + z^2)

#define MAX_VECTOR          2

int main (void)
{
    vector *vector_object[MAX_VECTOR];
    char *name[MAX_VECTOR] = {
        "VECTOR_A",
        "VECTOR_B"
    };

    vector_info_allocation(vector_object, name);

    random_seed_config();


    return 0;
}
