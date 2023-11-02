#include <stdio.h>
#include "dice_game.h"
#include "random_generator.h"

#define MAX			6
#define MIN			1

int dice_number = 0;
// 실제 헤더 파일에 있는 extern int dice_number를 통해
// 이 dice_game.c 에 있는 dice_number 변수를 사용하겠음을 의미합니다.

void roll_dice(void)
{
	dice_number = generate_random(MIN, MAX);
}

void print_dice_number(void)
{
	printf("굴려서 나온 주사위 숫자 = %d\n", dice_number);
}
