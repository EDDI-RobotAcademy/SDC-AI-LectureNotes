#include <stdio.h>
#include "utility/random/random.h"

#define MIN     -100
#define MAX     100

// Q1. 실수와 정수를 입력받고 
// 그 값을 함수의 인자로 넘겨 두 수의 곱을 실수형으로 반환하여 출력하라
// Q2. 두 개의 정수(num1, num2)를 입력받고 num1 << num2 값을 구하는 함수를 작성하고
// 최종적으로 결과값을 출력하도록 만드시오.

// Q1 전용 함수
void print_and_multiply_two_number(int a, float b)
{
    printf("a = %d\n", a);
    printf("b = %.2f\n", b);
    printf("a * b = %4.2f\n", a*b);
}

// Q2 전용 함수
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

// Q3 전용 함수
void seperate_integer_and_decimals(float num)
{
    printf("입력받은 실수는 %.2f입니다.\n", num);

    int index = MIN - 1;
    int integral_part;
    while ((num - index) > 1)
    {
        index++;
    }

    integral_part = index + 1;

    printf("정수부분 = %d\n", integral_part);
    printf("소수부분 = %.2f\n", num-integral_part);
}

int main (void)
{
    random_config();
    
    // Q1.
    int a = generate_random_integer(MIN, MAX);
    float b = generate_random_realnumber(MIN, MAX);
    print_and_multiply_two_number(a, b);

    // Q2.
    int num1 = generate_random_integer(MIN, MAX);
    int num2 = generate_random_integer(MIN, MAX);
    check_larger_number_and_print_result(num1, num2);

    // Q3.
    float num = generate_random_realnumber(MIN, MAX);
    seperate_integer_and_decimals(num);

    return 0;
}