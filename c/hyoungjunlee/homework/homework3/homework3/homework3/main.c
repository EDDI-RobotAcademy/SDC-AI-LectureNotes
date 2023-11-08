#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "player_info.h"




int main()
{
	input_player_name("first_player");
	input_player_name("second_player");

	random_config();
	roll_dice(0);
	roll_dice(1);
	winner_check(0, 1);

	return 0;
}