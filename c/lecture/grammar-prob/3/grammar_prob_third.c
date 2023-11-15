// 2번에서 만든 랜덤 숫자가 2로 나눠서 나머지가 1인 경우만 출력하세요.
#include "grammar_prob_third.h"

void print_number_if_even(int generated_random_number)
{
    if (generated_random_number % 2 == 0) 
    {
        printf("이거 짝수임: %d\n", generated_random_number);
    }
}