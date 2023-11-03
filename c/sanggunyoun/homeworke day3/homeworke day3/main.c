#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "dice_game.h"
#include "player.h"
#include "print_random.h"
#include "random_generator.h"

#define LOOP_MAX 1

int main(void)
{
	srand(time(NULL));

	int loop_count = 0;


	char player1[32] = "안녕";
	char player2[32] = "하세";

	int player1dice = player1;
	int player2dice = player2;
	
	player1dice = roll_dice();
	printf("안녕의 주사위는 %d\n", player1dice);

	player2dice = roll_dice();
	printf("하세의 주사위는 %d\n", player2dice);

	while (loop_count++ < LOOP_MAX)
	{
		printf("loop_count = %d\n", loop_count);
		roll_dice();
		print_dice_number();
	}

	set_player_name("안녕");
	print_player_name();

	while (loop_count++ < LOOP_MAX)
	{
		printf("loop_count = %d\n", loop_count);
		roll_dice();
		print_dice_number();
	}

	set_player_name("하세");
	print_player_name();


	// if문으로 안녕, 하세 주사위값을비교( == , >, <)
	// 승부 메시지 출력 {printf("승리")},{printf("패배")},printf{("무승부")}

	return 0;
}
