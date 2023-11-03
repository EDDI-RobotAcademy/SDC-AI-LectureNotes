#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>




int dice() {
	return rand() % 6 + 1;
}
int main() {
	srand(time(NULL));

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
