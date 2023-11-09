#include <stdio.h>
#include "player.h"
#include "random_generator.h"

#define MAX_DICE_COUNT		2

const int min = 1;
const int max = 6;

int dice_num[PLAYER_COUNT][MAX_DICE_COUNT];
int dice_total[PLAYER_COUNT];

void roll_dice(const int player_index) {	
	dice_num[player_index][0] = generate_random(min, max);
	if (dice_num[player_index][0] % 2 == 0) {
		dice_num[player_index][1] = generate_random(min, max);
	}

	dice_total[player_index] = dice_num[player_index][0] + dice_num[player_index][1];

	if (dice_num[player_index][1] == 2) {
		dice_total[player_index] += 3;
	}
	else if(dice_num[player_index][1] == 4) {
		dice_total[player_index] = 0;
	}
	else if(dice_num[player_index][1] == 3){
		dice_total[1 - player_index] -= 4;
	}
	
}

void print_dice(void) {
	int i, j;

	for (i = 0; i < PLAYER_COUNT; i++) {
		for (j = 0; j < MAX_DICE_COUNT; j++) {
			if (dice_num[i][j] != 0) {
				printf("%d번째 사용자 %s의 %d번째 주사위 눈금 = %d\n", i + 1, player[i], j + 1, dice_num[i][j]);
			}
		}
	}
}