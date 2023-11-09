#include <stdio.h>
#include "roll_dice.h"
#include "player.h"

void print_winner(void) {
	if (roll_dice_num[0] > roll_dice_num[1]) {
		printf("%s¥‘¿Ã ¿Ã∞ÂΩ¿¥œ¥Ÿ.\n", player[0]);
	}
	else if (roll_dice_num[0] < roll_dice_num[1]) {
		printf("%s¥‘¿Ã ¿Ã∞ÂΩ¿¥œ¥Ÿ.\n", player[1]);
	}
	else {
		printf("π´Ω¬∫Œ ¿‘¥œ¥Ÿ.\n");
	}
}