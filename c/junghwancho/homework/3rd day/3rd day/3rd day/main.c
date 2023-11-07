#include <stdio.h>
#include "random_generator.h"
#include "player.h"
#include "dice_fight.h"

int main(void)
{

	set_player1("X");
	set_player2("Y");

	dice_fight_test(player1, player2);


}