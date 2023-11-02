#include <stdio.h>
#include <time.h>
#include "random_generator.h"
#include "dice_game.h"
#include "player.h"
#define LOOP_MAX		2
int main(void)
{
	 
	int player_count = 0;
	char name1[PLAYER_NAME_MAX];
	char name2[PLAYER_NAME_MAX];
	int player1_dice_number = 0;
	int player2_dice_number = 0;

	/*while (player_count++ < LOOP_MAX)
	{
		roll_dice();
		print_dice_number();
	}*/
	srand(time(NULL));
	set_player_name("me");
	int leng1 = strlen(player_name);
	strncpy(name1, player_name, leng1 + 1);
    printf("플레이어1 이름--> %s\n", name1);
	roll_dice();
	player1_dice_number = dice_number;
	printf("--1번 주사위 값%d---\n",player1_dice_number);
	print_dice_number();
	
	
	set_player_name("enemy");
	int leng2 = strlen(player_name);
	strncpy(name2, player_name, leng2 + 1);
	printf("플레이어1 이름--> %s\n", name2);
	roll_dice();
	player2_dice_number = dice_number;
	printf("--2번 주사위 값%d---\n", player1_dice_number);
	print_dice_number();
	
	printf("두 명의 주사위의 값은 ? %s :%d %s: %d\n", name1,player1_dice_number, name2,  player2_dice_number);

	if (player1_dice_number > player2_dice_number)
	{
		printf("me win");
	}
	else if (player1_dice_number == player2_dice_number)
	{
		printf("Draw");
	}
	else
	{
		printf("enemy win");
	}
	return 0;

}

