#include <stdio.h>
#include "win.h"
#include "dice.h"
#include "player.h"

void check_winner(const int index1, const int index2)
{
	if (player_each_dice_number[index1] > player_each_dice_number[index2])
	{
		printf("%s ´ÔÀÌ ½Â¸®ÇÏ¼Ì½À´Ï´Ù.\n", player_name[index1]);
	}
	else if (player_each_dice_number[index1] < player_each_dice_number[index2])
	{
		printf("%s ´ÔÀÌ ½Â¸®ÇÏ¼Ì½À´Ï´Ù.\n", player_name[index2]);
	}
	else
	{
		printf("¹«½ÂºÎ ÀÔ´Ï´Ù.\n");
	}
}