// C언어 문법 문제

#include <stdio.h>
#include "2/second.h"
#include "3/third.h"
#include "5/fifth.h"
#include "6/sixth.h"
#include "7/seventh.h"
#include "8/eighth.h"
#include "9/ninth.h"
#include "10/tenth.h"
#include "11/eleventh.h"
#include "12/twelve.h"

int main (void)
{

    int i;

    // 1번 문제: 아무 변수나 만들고 변수 값을 출력하세요.
    int a = 99;
    printf("1. 아무 변수: %d\n", a);
    
    // 2번 문제: 랜덤 숫자를 출력하세요.
    config_random_seed();
    int random_number = generate_random();
    printf("2. 랜덤 숫자= %d\n", random_number);

    // 3번 문제: 2번에서 만든 랜덤 숫자가 2로 나눠서 나머지가 1인 경우만 출력
    printf("3.");
    odd_number(random_number);

    // 4번 문제: 숫자 3숫자 20 사이의 모든 정수를 출력
    printf("4. 3부터 20까지 모든 정수 출력: ");

    for (i = 3; i < 21; i++)
    {
        printf("%5d", i);
    }
    printf("\n");

    // 5번 문제: 정수형 인자 1개를 파라미터로 받아 출력
    printf("5. 정수: %d\n", integer_parameter(5));    

    // 6번 문제: 정수형 인자 2개를 파라미터로 받아 더한 결과를 return 하세요
    printf("6. 두 정수를 더한 결과: %d\n", integer_two_parameter(1, 3));

    // 7번 문제: 정수형 배열에 랜덤 숫자 3개를 입력한 이후 배열에 들어 있는 숫자를 출력하세요.
    printf("7. 배열 출력: ");
    integer_array();

    // 8번 문제: 랜덤을 돌려서 임의의 개수의 정수형 동적 배열을 만들고 배열에 숫자를 넣은 이후 출력
    printf("8. 동적 배열 출력: ");
    integer_random_array();

    // 9번 문제: 정수형 배열에 아무 숫자나 넣고 이 배열을 파라미터로 받아 출력하는 함수 작성 
    int arr[3] = {3, 4, 5};
    printf("9. 정수형 배열 출력: ");
    integer_array_print(arr);

    // 10번 문제: 정수형 배열에 아무 숫자나 넣고 이 배열의 모든 값을 더해서 return 하는 함수를 작성하세요.
    int arr2[3] = {5, 6, 7};
    printf("10. 배열의 합은: %d\n", integer_array_sum(arr2));

    // 11번 문제: 아무런 구조체 대충 하나 만들고 내부에 값을 할당하여 출력
    integer_result result;
    add_Print(result);

    // 12번 문제: 구조체 내부에 char * 형태의 내용을 배치하고 이 내용에 값을 할당하여 출력

    return 0;
}
