#include <stdio.h>
#include "print_even.h"
#include "print_even_advanced.h"
#include "print_random.h"
#include "random_dice.h"
#include "dice_game.h"
#include "player.h"

#define LOOP_MAX	5

int main(void)
{
	const int random_number_count = 10;
	const int start = 3;
	const int end = 13;
	const int dice_count = 3;
	int loop_count = 0;

	char player1_name;
	char player2_name;
	int player1_score = 0;
	int player2_score = 0;

	//시작과 끝의 짝수 값을 출력하는 함수
	print_even_number_from_start_to_end(start, end);

	printf("조금 더 개선한 코드 \n");
	print_even_number_from_start_to_end_advanced(start, end);

	// random 숫자 10개 출력하기
	print_random_number(random_number_count);

	// 주사위를 3번 굴려서 나온 값 및 총합
	random_dice(dice_count);

	//while 문은 for문과 마찬가지로 반복문중 하나입니다.
	//보편적으로 for는 약간 복잡한 구조에서 많이 사용하는 편이고
	//while문은 단순이 뻉뻉이 돌릴려고 하면 사용하는 편입니다.
	// 물론 관습적인 부분이기 때문에 꼭 저렁게 할 필요도 없습니다.
	
	// -while의 동작 과정
	// 조건 비교는 if와 동일합니다
	// 소괄호 내의 조건을 만족하면 반복이 됩니다.
	// 소괄호 내의 조건을 만족하지 못하면 반복이 중단됩니다.
	//
	// loop_count가 LOOP_MAX(5) 보다 작다면 반복
	// 근데 '++'이 붙어 있기 때문에
	// loop_count는 반복마다 숫자가 1씩 증가하게 됩니다.

	//'++', '--'에는 전위 연산자와 후위 연산자 개념이 존재함
	// 전위는 앞 후위는 뒤에 '++loop_count', loop_count++
	while (loop_count++ < LOOP_MAX)
	{
		roll_dice();
		print_dice_number();
	}

	set_player_name("Hello");
	print_player_name();

	set_player_name("alpha");
	player1_name = player_name;
	print_player_name();
	set_player_name("beta");
	player2_name = player_name;
	print_player_name();

	roll_dice();
	player1_score = dice_number;

	roll_dice();
	player2_score = dice_number;


	if (player1_score < player2_score)
	{
		printf("%d는 %d %d는 %d으로 %d가 이겼습니다.", player1_name, player1_score, player2_name, player2_score, player2_name);
	}
	else
	{
		printf("%s는 %d %s는 %d으로 %s가 이겼습니다.", player1_name, player1_score, player2_name, player2_score, player2_name);
	}


	return 0;
}