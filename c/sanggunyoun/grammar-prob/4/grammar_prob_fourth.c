// 숫자 3 ~ 숫자 20 사이의 모든 정수를 출력하세요.
#include "grammar_prob_fourth.h"

void print_start_to_finish(const int start, const int finish)
{
    int i;

    for (i = start; i <= finish; i++)
    {
        printf("number = %2d\n", i);
    }
}