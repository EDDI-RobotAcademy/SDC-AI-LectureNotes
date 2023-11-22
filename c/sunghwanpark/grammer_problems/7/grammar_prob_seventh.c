#include "grammar_prob_seventh.h"
#include "../2/grammar_prob_second.h"
// 7. 정수형 배열에 랜덤 숫자 3개를 입력한 이후 배열에 들어 있는 숫자를 출력하세요.

#define ARRAY_MAX   3 

int *return_random_array_data (void)
{
    static int array[ARRAY_MAX] = {0};
    int i;

    for(i = 0; i < ARRAY_MAX; i++)
    {
        array[i] = generate_random(1,100);
    }
    return array;
}