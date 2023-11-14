#include <stdio.h>
#include "utility/random/random.h"

#define MIN     -100
#define MAX     100

// Q1. 실수와 정수를 입력받고 
// 그 값을 함수의 인자로 넘겨 두 수의 곱을 실수형으로 반환하여 출력하라

void print_numbers(int a, float b)
{
    printf("a = %d\n", a);
    printf("b = %2f\n", b);
}

void mul_two_number(int a, float b)
{
    printf("a * b = %4.2f\n", a*b);
}

int main (void)
{
    random_config();
    
    int a = generate_random_integer(MIN, MAX);
    float b = generate_random_realnumber(MIN, MAX);
    print_numbers(a, b);
    mul_two_number(a, b);

    return 0;
}