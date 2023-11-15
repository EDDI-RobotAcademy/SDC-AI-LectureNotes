#include "dice.h"
#include "random.h"

#define MIN		1
#define MAX		6

int roll_dice(void)
{
	return get_random_from_min_to_max(MIN, MAX);
}

/*roll_dice 함수를 정의하며, 해당 함수는 get_random_from_min_to_max를 호출하여, 최소값(MIN)과 최대값(MAX)에 사이에
해당되는 무작위 정수를 생성합니다.
*/