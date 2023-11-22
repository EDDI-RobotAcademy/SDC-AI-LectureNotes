// 정수형 배열에 아무 숫자나 넣고 이 배열을 파라미터로 받아 출력하는 함수를 작성하세요.
#include "grammar_prob_ninth.h"

#include "../utility/random.h"

int *alloc_array(int *count)
{
    int i;
    int *tmp_array;

    *count = generate_random(4, 8);

    tmp_array = (int *)malloc(sizeof(int) * (*count));

    for (i = 0; i < *count; i++)
    {
        tmp_array[i] = generate_random(3, 7);
    }

    return tmp_array;
}
