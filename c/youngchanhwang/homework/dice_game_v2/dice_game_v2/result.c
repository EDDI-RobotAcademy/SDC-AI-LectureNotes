

#include "dice_game.h"
#include "player.h"
#include "dice_skill.h"

void result(const int index1, const int index2)
{
	if (player_score_array[index1] == player_score_array[index2])
	{
		printf("¹«½ÂºÎÀÔ´Ï´Ù!!\n");
	}
	else
	{
		if (player_score_array[index1] < player_score_array[index2])
		{
			printf("%s ´ÔÀÌ ÀÌ°å½À´Ï´Ù!\n", player[index2]);
		}
		else if (player_score_array[index1] > player_score_array[index2])
		{
			printf("%s ´ÔÀÌ ÀÌ°å½À´Ï´Ù!\n", player[index1]);
		}
	}
}