// C언어 문법 문제

#include <stdio.h>
#include "2/second.h"
#include "3/third.h"
#include "7/seventh.h"
#include "8/eighth.h"
#include "10/tenth.h"

int main (void)
{

    int i;

    // 1번 문제: 아무 변수나 만들고 변수 값을 출력하세요.
    int a = 99;
    printf("아무 변수: %d\n", a);
    
    // 2번 문제: 랜덤 숫자를 출력하세요.
    config_random_seed();
    int random_number = generate_random();
    printf("랜덤 숫자= %d\n", random_number);

    // 3번 문제: 2번에서 만든 랜덤 숫자가 2로 나눠서 나머지가 1인 경우만 출력
    odd_number(random_number);

    // 4번 문제: 숫자 3숫자 20 사이의 모든 정수를 출력
    printf("3부터 20까지 모든 정수 출력: \n");

    for (i = 3; i < 21; i++)
    {
        printf("%5d", i);
    }
    printf("\n");

    // 5번 문제: 정수형 인자 1개를 파라미터로 받아 출력

    // 6번 문제: 정수형 인자 2개를 파라미터로 받아 더한 결과를 return 하세요

    // 7번 문제: 정수형 배열에 랜덤 숫자 3개를 입력한 이후 배열에 들어 있는 숫자를 출력하세요.
    printf("배열 출력: ");
    integer_array();

    // 8번 문제: 랜덤을 돌려서 임의의 개수의 정수형 동적 배열을 만들고 배열에 숫자를 넣은 이후 출력
    printf("동적 배열 출력: ");
    integer_random_array();

    // 9번 문제: 정수형 배열에 아무 숫자나 넣고 이 배열을 파라미터로 받아 출력하는 함수 작성 
    // -> 위에 문제를 이미 함수로 만들었는데...으으으으

    // 10번 문제: 정수형 배열에 아무 숫자나 넣고 이 배열의 모든 값을 더해서 return 하는 함수를 작성하세요.

    return 0;
}
