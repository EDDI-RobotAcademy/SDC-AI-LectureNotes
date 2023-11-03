#include <stdio.h>
#include "player.h"
#include "dice.h"
#include "fight.h"
#include "random_generator.h"

#define PLAYER_NUMBER 2

int main()
{

	set_player_info("æ»≥Á«œººø‰", player1);
	set_player_info("π›∞©Ω¿¥œ¥Ÿ", player2);

	random_config();

	roll_dice(0);
	roll_dice(1);

	fight(0,1);
	
	return 0;
}