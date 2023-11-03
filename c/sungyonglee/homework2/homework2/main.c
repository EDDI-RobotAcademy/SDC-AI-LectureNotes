#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "dice.h"
#include "random_generator.h"

#define MAX			6
#define MIN			1



int main(void)
{
	int dice_number1 = 0;
	int dice_number2 = 0;
	int winner_number = 0;


	srand(time(NULL));

	void roll_dice1(void);
	{
		dice_number1 = generate_random(MIN, MAX);
	}

	void print_dice_number1(void);
	{
		printf("player1 ");
		printf("굴려서 나온 주사위 숫자 = %d\n", dice_number1);
	}



	void roll_dice1(void);
	{
		dice_number2 = generate_random(MIN, MAX);
	}

	void print_dice_number2(void);
	{
		printf("player2 ");
		printf("굴려서 나온 주사위 숫자 = %d\n", dice_number2);
	}

	void pinrt_winner_number(void);
	{
		if (dice_number1 > dice_number2) {
			printf("\n승리자: player1");
			winner_number = dice_number1;
		}
		else if (dice_number1 < dice_number2) {
			printf("\n승리자: player2");
			winner_number = dice_number2;
		}
		else if (winner_number = dice_number2) {
			printf("\ndraw");
		}
		else {
			
		}
		printf("\n승리자의 주사위 숫자 = %d\n", winner_number);
	}
}