#include "random.h"

#include <time.h>
#include <stdlib.h>

void random_seed_config(void)
{
	srand(time(NULL));
}
/*random_seed_config 함수는 무작위 숫자 생성을 위한 함수.*/

int get_random_from_min_to_max(const int min, const max)
{
	return rand() % (max - min + 1) + min;
}
/*get_random_from_min_to_max 함수는 min과 max 사이 무작위 정수 값을 생성.*/