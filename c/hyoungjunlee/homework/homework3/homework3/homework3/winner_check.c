#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player_info.h"
#include "dice_game.h"
void winner_check(int player1, int player2)
{
	if (player_point[player1] > player_point[player2])
	{
		printf("%s의 점수 %d,\n%s의 점수 %d이므로\n%s승리!!", player_name[player1], player_point[player1], player_name[player2], player_point[player2], player_name[player1]);
	}
	else if (player_point[player1] < player_point[player2])
	{
		printf("%s의 점수 %d,\n%s의 점수 %d이므로\n%s승리!!", player_name[player1], player_point[player1], player_name[player2], player_point[player2], player_name[player2]);
	}

	else
		printf("%s의 점수 %d,\n%s의 점수 %d이므로\n 무승부!!", player_name[player1], player_point[player1], player_name[player2], player_point[player2]);
}