#include <stdio.h>
#include "player.h"

int roll_dice_num[PLAYER_COUNT];

const int min = 1;
const int max = 6;

void play_roll_dice(void) {
	int i;

	for (i = 0; i < PLAYER_COUNT; i++) {
		roll_dice_num[i] = generate_random(min, max);
		printf("%d번째 선수의 주사위눈금은 %d입니다.\n", i + 1, roll_dice_num[i]);
	}
}