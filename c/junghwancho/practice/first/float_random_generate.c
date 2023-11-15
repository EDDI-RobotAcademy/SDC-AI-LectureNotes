#include "float_random_generate.h"

#include <stdlib.h>
#include <time.h>

void float_config_random_seed(void)
{
    srand(time(NULL));
}

float float_generate_random(const float float_min, const float float_max)
{
    // 주어진 범위 내의 실수형 난수 생성
    
    float random_value = (float)rand() / (float)RAND_MAX;
    return float_min + random_value * (float_max - float_min);
}