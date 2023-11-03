#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
	set_player_info("원소");
	set_player_info("원술");

	print_player_info(0);
	print_player_info(1);

	random_config();
	roll_dice(0);
	roll_dice(1);

	print_dice_number(0);
	print_dice_number(1);

	int player1dice = print_dice_number(0);
	int player2dice = print_dice_number(1);


}




/*int main() {
	

	char player1 = "유비";
	char player2 = "조조";

	int player1dice = dice();
	printf("유비의 주사위는 %d\n", player1dice);

	int player2dice = dice();
	printf("쬬의 주사위는 %d\n", player2dice);

	if (player1dice < player2dice) {
		printf("쬬의 승리\n");
	}
	if (player1dice > player2dice) {
		printf("유비의 승리\n");

	}
	if (player1dice == player2dice) {
		printf("무승부입니다.");

	}
}
*/