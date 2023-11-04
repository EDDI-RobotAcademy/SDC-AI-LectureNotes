#include "dice_game.h"

void dice_skill_2(const int index)
{
	player_score_array[index] = player_score_array[index] + 2 + 3;
}

void dice_skill_3(const int index)
{
	if (index == 0) {
		player_score_array[0] = player_score_array[0] + 3;
		player_score_array[1] = player_score_array[1] - 4;
	}
	else
	{
		player_score_array[0] = player_score_array[0] - 4;
		player_score_array[1] = player_score_array[1] + 3;
	}
}

void dice_skill_4(const int index)
{
	player_score_array[index] = -100;
}
