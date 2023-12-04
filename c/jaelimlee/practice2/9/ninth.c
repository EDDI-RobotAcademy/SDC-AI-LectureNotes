// 9번 문제: 정수형 배열에 아무 숫자나 넣고 이 배열을 파라미터로 받아 출력하는 함수 작성 

#include "ninth.h"
#include <stdio.h>

void integer_array_print(int array[])
{
    // COUNT_ARRAY 는 임의로 3이라 지정하였음.
    for (int i = 0; i < COUNT_ARRAY; i++)
    {
        printf("%5d\n", array[i]);
    }

}