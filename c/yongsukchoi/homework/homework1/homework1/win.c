#include <stdio.h>
#include "player.h"
#include "dice.h"

void check_win(void) {
	if (dice_total[0] > dice_total[1]) {
		printf("%s의 점수 = %d\n", player[0], dice_total[0]);
		printf("%s의 점수 = %d\n", player[1], dice_total[1]);
		printf("%s가 승리하였습니다.\n", player[0]);
	}
	else if (dice_total[0] < dice_total[1]) {
		printf("%s의 점수 = %d\n", player[0], dice_total[0]);
		printf("%s의 점수 = %d\n", player[1], dice_total[1]);
		printf("%s가 승리하였습니다.\n", player[1]);
	}
	else {
		printf("%s의 점수 = %d\n", player[0], dice_total[0]);
		printf("%s의 점수 = %d\n", player[1], dice_total[1]);
		printf("무승부 입니다.\n");
	}
}