// 랜덤 숫자를 출력하세요.
#include "grammar_prob_second.h"
#include "../utility/random.h"

#include <stdio.h>

int generated_random_number;

void print_random_number(void)
{
    printf("random number: %d\n", generate_random(MIN, MAX));
}

void print_random_number_and_alloc_to_global(void)
{
    generated_random_number = generate_random(MIN, MAX);
    printf("global random number: %d\n", generated_random_number);
}

int get_allocated_global_random_number(void)
{
    return generated_random_number;
}

void print_random_number_from_main_parameter_transfer(const int min, const int max)
{
    printf("(main parameter transfer) random number: %d\n", generate_random(min, max));
}