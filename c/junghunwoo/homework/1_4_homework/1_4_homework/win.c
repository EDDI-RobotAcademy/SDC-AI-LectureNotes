#include "win.h"
#include "player.h"
#include"dice_game.h"

void check_winner(const int index)
{
	if (player_each_dice_score1 > player_each_dice_score2)
	{
		printf("%d 대 %d 으로 player 번호 %d = %s 님이 승리하셨습니다!\n", player_each_dice_score1, player_each_dice_score2, index, player[index]);
	}
	else if (player_each_dice_score1 < player_each_dice_score2)
	{
		printf("%d 대 %d 으로 player 번호 %d = %s 님이 승리하셨습니다!\n", player_each_dice_score1, player_each_dice_score2, 1, player[1]);
	}
	else
	{
		printf("무승부입니다!");
	}
}