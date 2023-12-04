#include <stdio.h>
#include <stdlib.h>
#include "random/random.h"
#include "seperation/seperation.h"
#include "6/practice6.h"
#include "13/practice13.h"
#include "14/practice14.h"
#include "15/practice15.h"


int main (void)
{
    // 1. 실수 정수 곱 실수형으로 반환 출력
    coinfig_random_seed();
    int int_num = generate_random();
    //double double_num = generate_random();

    //printf("실수와 정수의 곱: %.f\n", int_num * double_num);

    //2. num1 << num2
    int num1 = generate_random();
    int num2 = generate_random();
    int shift_result;
    shift_result = num1 << num2;
    printf("nu1 << num2: %d\n", shift_result);

    //3. 실수 입력받아 소숫점 분리. 정수 분리 함수 작성
    double num3 = generate_random();

    printf("실수: %.f\n", num3);
    integer_separation(num3);
    decimal_point_separation(num3);

    // 6번. 
    int x = 3;
    int y = 4;

    printf("%d\n", square(3, 4));


    // 10번.
    int a = 9;
    int b = 15;

    if (a < 10 && b < 20)
    {
        printf("a: %d, b: %d\n", a, b);
    }
    
    if (a > 20 || b <20)
    {
        printf("a: %d, b: %d\n", a, b);
    }

    if (a = ~b)
    {
        printf("a와 b는 다르다");
    }

    // 11번.
    int c = 33;
    printf("10진수 33에 ~연산을 취한 결과: %d\n", ~c);


    // 13번.
    printf("결과 = %d\n", doit(6, 4) * letsgo(1, 2));


    // 14번.
    distinction(3, 6);
    distinction(7, 5);

    // 15번.
    integer_result result;
    add_Print(result);

    return 0;
}
