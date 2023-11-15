#include <stdio.h>
#include "float_random_generate.h"
#include "int_random_generate.h"

const int min = 1;
const int max = 10;

// 함수 프로토타입 선언
float get_float_number(void);
int get_int_number(void);

void print_float_number(float number);
void print_int_number(int number);

float multiply(float x, int y); 

void print_multiply_number(float result);

int main(void)
{
    // 랜덤 시드 설정
    float_config_random_seed();
    int_config_random_seed();

    // 실수와 정수 랜덤 숫자 얻기
    float floatNumber = get_float_number();
    int intNumber = get_int_number();

    // 얻은 숫자 출력
    print_float_number(floatNumber);
    print_int_number(intNumber);

    float result = multiply(floatNumber, intNumber);

    print_multiply_number(result);

    return 0;
}


float get_float_number(void)
{
    return float_generate_random(min, max);
}

int get_int_number(void)
{
    return int_generate_random(min, max);
}

void print_float_number(float number)
{
    printf("실수의 값: %f\n", number);
}

void print_int_number(int number)
{
    printf("정수의 값: %d\n", number);
}

float multiply(float x, int y)
{
    return x * y;
}

void print_multiply_number(float result)
{
    printf("곱샘 값: %f\n", result);
}