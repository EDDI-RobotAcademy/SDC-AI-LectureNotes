#include "winner.h"
#include "dice.h"
#include "skill.h"


void winner(const int index1, const int index2)
{
	if (player_each_dice_number[index1] > player_each_dice_number[index2])
	{
		printf("player ¹øÈ£ %d = %s ´ÔÀÌ ½Â¸®ÇÏ¼Ì½À´Ï´Ù!", index1, player[index1]);
	}
	else if (player_each_dice_number[index1] < player_each_dice_number[index2])
	{
		printf("player ¹øÈ£ %d = %s ´ÔÀÌ ½Â¸®ÇÏ¼Ì½À´Ï´Ù!", index2, player[index2]);
	}
	else
	{
		printf("¹«½ÂºÎÀÔ´Ï´Ù.");
	}
}