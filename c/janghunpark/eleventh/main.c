#include <stdio.h>
#include <math.h>

#include "utility/random/random.h"

#include "1/first_prob.h"
#include "2/second_prob.h"
#include "3/third_prob.h"
#include "4/fourth_prob.h"
#include "5/fifth_prob.h"
#include "6/sixth_prob.h"
#include "8/eighth_prob.h"
#include "9/ninth_prob.h"
#include "10/tenth_prob.h"
#include "13/thirteenth_prob.h"
#include "14/fourteenth_prob.h"
#include "15/fifteenth_prob.h"

#define MIN     -100
#define MAX     100

int main (void)
{
    random_config();
    
    float doit_result;
    int letsgo_result;
    float mul_result;
    float add_result;

    // Q1.
    int a = generate_random_integer(MIN, MAX);
    float b = generate_random_realnumber(MIN, MAX);
    print_and_multiply_two_number(a, b);

    // Q2.
    bit_calculation(2, 10); // 이게 실제 문제가 의도한 바

    // Q3.
    float num = generate_random_realnumber(MIN, MAX);
    seperate_integer_and_decimals(num);

    // Q4. 
    check_float_double_size();

    // Q5. && = and 연산, || = or 연산
    printf("5. result = %d\n", shortcut_test(30));
    printf("5. result = %d\n", shortcut_test(11));
    printf("5. result = %d\n", shortcut_test(8));
    printf("5. result = %d\n", shortcut_test(1));

    // Q6. 2의 n승 단위로 정렬하는 기법 (미해결, 풀이 참조)
    printf("6. result = %d\n", number_align_with_parameter(10, 1040));
    printf("6. result = %d\n", number_align_with_parameter(5, 776));
    printf("6. result = %d\n", number_align_with_parameter(2, 123));
    printf("6. result = %d\n", number_align_with_parameter(5, 64));

    // Q7.
    // 함수 프로토타입을 모르기 때문에 최상단에 함수 프로토타입을 작성하면 문제가 해결됨

    // Q8. 변수의 정의 출력
    definition_of_variables();

    // Q9. overflow, underflow 현상 출력; char range base
    printf("overflow = %d\n", test_overflow(127));
    printf("underflow = %d\n", test_underflow(-128));

    // Q10. 비트 연산 결과 출력
    printf("and 연산 결과 = %d\n", and_data(10, 14)); // 1010, 1110 -> 1010 = 10
    printf("or 연산 결과 = %d\n", or_data(12, 10)); // 1100, 1010 -> 1110 = 14
    printf("xor 연산 결과 = %d\n", xor_data(5, 10)); // 101, 1010 -> 1111 = 15
    printf("not 연산 결과 = %d\n", not_data(10)); // 부호 뒤집고 -1 -> -11

    // Q11. not 연산자 결과 출력
    printf("~33 = %d\n", not_data(33)); // 부호 뒤집고 -1 -> -34

    // Q12. Memory 정의 복습
    // Memory 구조 (Stack, Heap, Data, Text)
    // Stack = 지역변수, Heap = 동적 할당, Data = 전역변수, Text = 기계어 

    // Q13. 나머지, 덧셈, 곱셈 함수 활용
    doit_result = doit(200, 15);
    letsgo_result = letsgo(13, 6);
    mul_result = mul(doit_result, letsgo_result);
    printf("doit_result = %.2f, letsgo_result = %d, mul_result = %.2f\n", doit_result, letsgo_result, mul_result);

    // Q14. 난수 두 개 중 어떤 수가 더 큰지 비교 판단
    int num1 = generate_random_integer(MIN, MAX);
    int num2 = generate_random_integer(MIN, MAX);
    check_larger_number_and_print_result(num1, num2);

    // Q15. 실수 덧셈 이후 정수부만 출력
    add_result = add(3, 7.7);
    print_integer_part(add_result);

    return 0;
}