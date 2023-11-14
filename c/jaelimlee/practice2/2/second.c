// 2번 문제. 랜덤 숫자를 출력하세요

#include "second.h"

#include <stdlib.h>
#include <time.h>

void config_random_seed(void)
{
    srand(time(NULL));
}

int generate_random()
{
    return rand();
}

int generate_random2(const int min, const int max)
{
    return rand() % (max - min + 1) + min;
}