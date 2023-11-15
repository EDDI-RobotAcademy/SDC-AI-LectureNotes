// 랜덤 숫자를 출력하세요.
#include "grammar_prob_second.h"
#include "../utility/random.h"

#include <stdio.h>

void print_random_number(void)
{
    printf("random number: %d\n", generate_random(MIN, MAX));
}