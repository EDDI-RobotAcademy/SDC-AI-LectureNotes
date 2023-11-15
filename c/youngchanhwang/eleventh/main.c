#include <stdio.h>
#include <stdbool.h>

#include "utility/random.h"
#include "mul.h"
#include "bitt.h"
#include "three/double_int.h"
#include "three/double_un.h"
#include "13/func_doit.h"
#include "13/func_letsgo.h"
#include "15/return_int.h"
#include "clangmun.h"

void q_one(void)
{

    int int_a;
    double double_a, mul_result;

    int_a = random_int();
    double_a = random_double();
    mul_result = mul_double_int(double_a, int_a);
    print_mul_double_int(double_a, int_a, mul_result);
}
void q_two(void)
{
    int num1, num2, num_result;
    num1 = random_int();
    num2 = random_int();
    num_result = num_bit(num1, num2);
    print_num_bit(num1,num2,num_result);

}
void q_three(void)
{
    double num, n_int;
    int int_num;

    num = random_double();
    int_num = only_int(num);
    n_int = no_int(num);
    printf("실수 = %f, 정수부분 = %d, 소수점만 = %f\n",num, int_num, n_int);

}



int main (void)
{
    random_seed_config();

    
    q_one();
    q_two();
    q_three();
    // 4 번
    // float는 4byte double은 8byte


    // 7 번
    // 함수 프로토타입을 모르기 때문에 최상단에 함수 프로토타입을 둘 수 없다.


    // 8 번
    // 특정 데이터 타입의 정보를 저장 할 수 있는 메모리 공간


    //12 번
    // Memory 구조 (Stack, Heap, Data, Text)에 대해서 기술하시오.
    // Stack : 지역변수
    // Heap : new, malloc 등의 동적 할당
    // Data : 정적 변수, 전역 변수
    // Text : 기계어


    // 13
    printf("result = %d\n", doit(5,3) * letsgo(5,3));

    // 14
    int num1, num2;
    num1 = random_int();
    num2 = random_int();
    printf("14\n");
    printf("num1 = %d, num2 = %d\n",num1,num2);
    printf("num1 == num2 ? %s\n", num1==num2 ? "true" : "false");
    printf("num1 < num2 ? %s\n", num1<num2 ? "true" : "false");
    printf("num1 > num2 ? %s\n\n", num1>num2 ? "true" : "false");


    // 15
    printf("3+7.7 정수로 = %d\n" , return_int(3,7.7));

    printf("33 ~ ?? %d\n", ~35);


    printf("\n");
    clangmun();


    return 0;
}
