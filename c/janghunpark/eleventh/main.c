#include <stdio.h>
#include "utility/random/random.h"

#define MIN     -100
#define MAX     100

// Q1. 실수와 정수를 입력받고 
// 그 값을 함수의 인자로 넘겨 두 수의 곱을 실수형으로 반환하여 출력하라
// Q2. 두 개의 정수(num1, num2)를 입력받고 num1 << num2 값을 구하는 함수를 작성하고
// 최종적으로 결과값을 출력하도록 만드시오.

void print_numbers(int a, float b)
{
    printf("a = %d\n", a);
    printf("b = %2f\n", b);
}

void mul_two_number(int a, float b)
{
    printf("a * b = %4.2f\n", a*b);
}

void check_larger_number_and_print_result(int num1, int num2)
{
    printf("num1 = %d, num2 = %d\n", num1, num2);

    if (num1 > num2)
    {
        printf("1번 숫자가 더 큽니다!\n");
    }
    else if (num1 < num2)
    {
        printf("2번 숫자가 더 큽니다!\n");
    }
    else
    {
        printf("두 숫자는 같습니다!\n");
    }
}

int main (void)
{
    random_config();
    
    // Q1.
    int a = generate_random_integer(MIN, MAX);
    float b = generate_random_realnumber(MIN, MAX);
    print_numbers(a, b);
    mul_two_number(a, b);

    // Q2.
    int num1 = generate_random_integer(MIN, MAX);
    int num2 = generate_random_integer(MIN, MAX);
    check_larger_number_and_print_result(num1, num2);

    return 0;
}