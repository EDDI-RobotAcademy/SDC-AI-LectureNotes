#include <stdio.h>
#include "quiz1/quiz1.h"
#include "13/quiz13.h"
#include "14/quiz14.h"
#include "15/quiz15.h"

int main (void)
{
    // quiz 1
    float quiz1_num1 = 1.5f;
    int quiz1_num2 = 3;
    float result_quiz1 = quiz1_num1 * quiz1_num2;
    printf("\n");
    printf("quiz1\n");
    printf("실수 num1 값: %f\n", quiz1_num1);
    printf("정수 num2 값: %d\n", quiz1_num2);
    printf("1번 결과값(두 값의 곱): %5.2f\n", result_quiz1);
 
    // quiz 3
    int quiz2_num1 = 5;
    int quiz2_num2 = 8;

    float quiz3_num = 1.5f;
    int quiz3_num_int = quiz3_num;
    float quiz3_result1 = quiz3_num - quiz3_num_int;
    float quiz3_result2 = quiz3_num - quiz3_result1;
    printf("\n");
    printf("quiz3\n");
    printf("num 값: %f\n", quiz3_num);
    printf("3번 결과값(소수): %5.2f\n", quiz3_result1);
    printf("3번 결과값(정수): %5.2f\n", quiz3_result2);

    // quiz 4
    // float 과 double 자료형의 저장 방식에 대해 서술
    // =>   float 은 4 바이트, double 은 8 바이트

    // quiz 5
    // shortcut 동작 방식에 대해 서술 (&&와 ||에 대해서 각각)
    // =>   && : AND, 양쪽 다 True 이어야 True
    //      || : OR, 한쪽이라도 True 이면 True

    // quiz 8
    // 변수의 정확한 정의에 대해 기술
    // =>   고정되지 않고 변할 수 있는 데이터를 저장하는 메모리 공간

    // quiz 9
    // Overflow 와 Underflow 는 어떤 경우에 나는지 기술
    // 

    // quiz 10
    // and, or, xor, not 동작 방식에 대해 기술하고 예를 들어 각각 연산
    // =>   and, or, xor, not 동작 방식
    //      and : 2 개 이상의 조건이 만족 했을 때 참
    //      or : 2 개 이상의 조건 중 1 개 이상이 만족 했을 때 참
    //      xor : 2 개 이상의 조건 중 1 개 이상이 거짓일 때 참
    //      not : 거짓일 때 참, 참일 때 거짓

    // quiz 12
    // Memory 구조 (Stack, Heap, Data, Text)

    // quiz 13
    printf("\n");
    printf("quiz13\n");
    printf("13-1. result = %d\n", doit(7, 4));
    printf("13-2. result = %d\n", letsgo(6, 2));
    printf("13-3. result = %d\n", doit(7, 4) * letsgo(6, 2));

    // quiz 14
    printf("\n");
    printf("quiz14\n");
    quiz14();

    // quiz 15
    printf("\n");
    printf("quiz15\n");
    printf("15. result = %d\n", quiz15(3, 7.7));

    return 0;
}
