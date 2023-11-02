#include <stdio.h>
#include "player.h"
#include "dice.h"
#include "random.h"

#define MAX 6
#define MIN 1


int main(void)
{
	int rolling = 1;
	int dice1;
	int dice2;
	

	set_player_name("Â¯±¸");
	print_player_name();
	
	dice1 = set_dice_number(rolling);
	printf("ÁÖ»çÀ§ °ª: %2d\n", dice1);
	
	set_player_name("¸Í±¸");
	print_player_name();
	
	dice2 = set_dice_number(rolling);
	printf("ÁÖ»çÀ§ °ª: %2d\n", dice2);

	if (dice1 > dice2)
	{
		printf("Â¯±¸ ½Â");
	}
	else if (dice1 < dice2) {
		printf("¸Í±¸ ½Â");
	}
	else {
		printf(" ¹«½ÂºÎ ");
	}
	
	

	return 0;
}