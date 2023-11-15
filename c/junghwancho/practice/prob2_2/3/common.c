// 3. 위의 2번에서 만든 랜덤 숫자가 2로 나눠서 나머지가 1인 경우만 출력하세요.

// 1. bool 기능 사용해서 홀수 판정
// 2. print

#include <stdbool.h>
#include "common.h"

bool check_odd_number(int random_number)
{
    return (random_number % 2) ? false : true;
}