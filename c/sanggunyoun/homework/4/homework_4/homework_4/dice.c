#include "dice.h"
#include "random.h"

		//		-주사위 눈금의 최소,최대

#define MIN			1
#define MAX			6


		//		-random.c에 가보면 get_random_from_min_to_max => 정보가있음
int roll_dice(void)
{
	return get_random_from_min_to_max(MIN, MAX);
}