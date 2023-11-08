#include <stdio.h>
#include "print_even.h"
#include "print_even_advanced.h"
#include "print_random.h"
#include "random_generator.h"
#include "dice_game.h"
#include "player.h"
#include "dice_fight.h"

#define LOOP_MAX		5

int main(void)
{
	const int random_number_count = 10;
	const int start = 3;
	const int end = 13;

	int loop_count = 0;

	// start ~ end 사이의 숫자에서 짝수를 출력
	print_even_number_from_start_to_end(start, end);

	printf("조금 더 개선한 코드!\n");
	print_even_number_from_start_to_end_advanced(start, end);

	// random 숫자 10개 출력하기
	print_random_number(random_number_count);

	// while 문은 for문과 마찬가지로 반복문중 하나
	// 보편적으로 for는 약간 복잡한 구조에서 많이 사용하는 편이며
	// while은 단순히 뺑뺑이 돌릴려고 하면 사용하는 편
	// 관습적인 부분이기 때문에 꼭 ! 따를 필요는 없다.

	// while의 동작 과정
	// - 조건 비교는 if와 동일함
	// - 소괄호 내 조건을 만족하면 반복
	// - 소괄호 내의 조건을 만족하지 못하면 반복 중단

	// loop_count가 LOOP_MAX(5) 보다 작다면 반복
	// 근데 ++이 붙어 있으니 loop_count는 반복마다 1씩 증가

	// '++', '--' 는전위 연산자와 후위 연산자 개념이 존재
	// 전위 연산자의 경우 '++loop_count' 형태가 됨
	// 이 경우에는 아래 조건이 비교 되기 이전에 먼저 덧셈이 계산됨
	// 후위 연산자의 경우 'loop_count++' 형태가 됨
	// 이 경우에는 조건이 먼저 비교되고 이후 덧셈
	// ex) ++loop_count 시 4번 동작
	while (loop_count++ < LOOP_MAX)
	{
		printf("loop_count = %d\n", loop_count); //< 카운트 궁금하면 써봐
		roll_dice();
		print_dice_number();

		printf("난 그냥 찌글래: %d\n", dice_number);
	}

	set_player_name("hello");
	print_player_name();

	set_player1("X");
	set_player2("Y");

	dice_fight(char player1[], char player2[])






		return 0;

}
