#include <stdio.h>

#include "dice.h"
#include "player.h"
#include "random_gen.h"

int player_each_dice_number[MAX_PLAYER_NUMBER];
int player_index_count;

const int min = 1;
const int max = 6;


void roll_dice(const int index)
{
	player_each_dice_number[index] = generate_random(min, max);
}

void print_dice_number(const int index)
{
	// printf가 리턴값이 있음
	// 문자를 몇 바이트 출력 했는지를 리턴함
	// 어셈블리에서 함수의 리턴값은 어디로 가나요 ? ax 레지스터
	printf("%d 번 플레이어의 주사위 눈금은 %d\n", index, player_each_dice_number[index]);
}
