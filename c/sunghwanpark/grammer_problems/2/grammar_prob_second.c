#include "grammar_prob_second.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//2. 랜덤 숫자를 출력하세요.


void random_config(void)
{
    srand(time(NULL));
}

int generate_random(const int min, const int max)
{
    return rand() %(max-min+1)+min;
}