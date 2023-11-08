#include <stdio.h>
#include <stdlib.h>
#include "skill.h"

#define MAX_PLAYER_NUMBER	2

int main(void) 
{
	set_player_info("원소");
	set_player_info("원술");

	print_player_info(0);
	print_player_info(1);

	random_config();

	// 홀수 케이스를 보기 위해 강제 주입
	
	
	// roll_dice()가 존재하지 않으므로 전역 변수 특성상 초기값인 0이 출력되고 있음
	// roll_dice()를 통해 player1_dice 값을 설정해야 하는데 print_dice에서 작업을 하고 있음 ???
	// 그리고 C언어 표준도 안지켜지고 있음 (변수 선언은 최상위에 해야함)
	/*
	int player1 = print_dice_number(0);
	int player2 = print_dice_number(1);
	*/

	/* 위의 사항을 통해 가독성 문제를 해결 했지만 여전히 문제가 존재함*/
	// printf의 리턴값이 player_dice에 반영되는 기현상이 나타나고 있음
	// 그러므로 올바른 로직의 사용이 필요함
	//int player1_dice = print_dice_number(0);
	//int player2_dice = print_dice_number(1);
	int player1_first_dice = roll_dice(0);
	int player2_first_dice = roll_dice(1);

	print_dice_number(0);
	print_dice_number(1);
	
	// 여기서 결국 배열에는 2가 들어 있기 때문에
	// -4를 해도 -2가 되었음
	// int* player_scores[MAX_PLAYER_NUMBER] = {2};

	// int number1 = 3, number2 = 7;
	// int *arr[2] = { &number1, &number2 };
	// 현재 배열에 저장되는 정보는 메모리가 아니라 숫자임
	// 그러므로 배열을 아래와 같이 작성하면 안됨
	// int* player_scores[MAX_PLAYER_NUMBER] = { 0 };
	int player_scores[MAX_PLAYER_NUMBER] = { 0 };

	skill(0, player1_first_dice, player_scores);
	skill(1, player2_first_dice, player_scores);

	// 0과 1의 용도가 뭐였지 ?
	printf("after skill\n");
	printf("플레이어 %d의 현재 점수: %d\n", 0, player_scores[0]);
	printf("플레이어 %d의 현재 점수: %d\n", 1, player_scores[1]);

	if (player_scores[0] > player_scores[1])
	{
		printf("플레이어 0이 승리했습니다!\n");
	}
	else if (player_scores[0] < player_scores[1])
	{
		printf("플레이어 1가 승리했습니다!\n");
	}
	else
	{
		printf("무승부입니다!\n");
	}
	
	return 0;
}

