#include "player_attack.h"
#include "dice.h"

void attack_player(int index)
{
	if (index == 0)
	{
		player_each_dice_number[++index] = -3;
	}
	else
	{
		player_each_dice_number[--index] -= 3;
	}
}
