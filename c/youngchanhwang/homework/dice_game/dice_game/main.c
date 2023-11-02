#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#include "random_generator.h"
#include "dice.h"
#include "player.h"
#include "battle.h"
int main(void)
{

	char player1[] = "Ã¶¼ö";
	char player2[] = "Â¯±¸";

	srand(time(NULL));


	set_player1_name(player1);
	set_player2_name(player2);
	print_player1_name();
	print_player2_name();


	battle(player1, player2);


}