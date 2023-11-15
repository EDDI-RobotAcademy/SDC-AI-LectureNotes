//랜덤 숫자를 출력하세요.
#include "grammar_prob_second.h"
#include "../utility/random.h"

#include <stdio.h>

void print_random_number(void)
{
    printf("random_number : %d\n",generate_random(MIN,MAX));
}

void print_random_number_from_main_parameter_transfer(const int min, const int max)
{
    printf("(main prameter transfer)random_number : %d\n",generate_random(min,max));
}