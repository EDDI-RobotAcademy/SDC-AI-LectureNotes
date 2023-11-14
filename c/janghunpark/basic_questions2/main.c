#include <stdio.h>

#include "1/ski.h"
#include "2/divisor.h"
#include "3/multiples_of_three.h"
#include "9/mutiplication_table.h"

int main (void)
{
    // 1번 문제
    printf("< 1번 문제 풀이 >\n");
    ski_cost_evaluation(37500, 2);
    ski_cost_evaluation(37500, 5);

    // 2번 문제
    printf("< 2번 문제 풀이 >\n");
    divisor_generation(32);
    divisor_generation(60);

    // 3번 문제
    printf("< 3번 문제 풀이 >\n");
    addition_of_multiples_of_three(1000);

    // 9번 문제
    printf("< 9번 문제 풀이 >\n");
    multiplication_table();

    return 0;
}