#include <stdio.h>
#include <stdlib.h>
#include "skill.h"


int main(void) 
{
	set_player_info("원소");
	set_player_info("원술");

	print_player_info(0);
	print_player_info(1);

	random_config();
	roll_dice(0);
	roll_dice(1);

	int player1 = print_dice_number(0);
	int player2 = print_dice_number(1);

	int* player_scores[] = {2};

	skill(0, player1, player_scores);
	skill(1, player2, player_scores);

	printf("플레이어 1의 현재 점수: %d\n", player_scores[0]);
	printf("플레이어 2의 현재 점수: %d\n", player_scores[1]);

	

	if (player_scores[0] > player_scores[1])
	{
		printf("플레이어 1이 승리했습니다!\n");
	}
	else if (player_scores[0] < player_scores[1]) 
	{
		printf("플레이어 2가 승리했습니다!\n");
	}
	else
	{
		printf("무승부입니다!\n");
	}
	
	return 0;
}

