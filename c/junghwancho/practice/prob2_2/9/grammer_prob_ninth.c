// 9. 정수형 배열에 아무 숫자나 넣고 이 배열을 파라미터로 받아 출력하는 함수를 작성하세요.
// 1. 정수형 배열 생성
// 2. 이 배열을 출력할 함수 생성

#include "grammer_prob_ninth.h"
#include  "../2/random_number_generator.h"
#include <stdio.h>

int *alloc_array(int *count)
{
    int i;
    int *tmp_array

    *count = random_generate(4, 8);
    int *tmp_array = (int *)malloc(sizeof(int)*(count));

    for (i=0; i< *count; i++)
    {
        tmp_array[i] = random_generate(4, 8);
    }
return tmp_array;

}