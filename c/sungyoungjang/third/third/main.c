#include <stdio.h>
#include "print_even.h"
#include "print_even_adv.h"
#include "print_random.h"
#include "dice_game.h"
#include "player.h"

#define LOOP_MAX 5

int main(void)
{
	const int random_number_count = 10;
	const int start = 3;
	const int end = 13;
	
	int loop_count = 0;

	// 시작 ~ 끝 사이의 숫자에서 짝수를 출력
	print_even_number_from_start_to_end(start, end);

	printf("조금 더 개선한 코드!\n");
	print_even_number_from_start_end_adv(start, end);
	
	//random 숫자 10개 출력하기
	print_random_number(random_number_count);
	
	// while 문은 for문과 마찬가지로 반복문중 하나입니다.
	// 보편적으로 for는 약간 복잡한 구조에서 많이 사용하는 편이고
	// 물론 관습적인 부분이기 때문에 꼭 저렇게 할 필요는 없음

	// - while의 동작과정\
		조건 비교는 if와 동일합니다.\
		소괄호 내의 조건을 만족하면 반복이 됩니다.\
		소괄호 내의 조건을 만족하지 못하면 반복이 중단됩니다.\

	// loop_count가 LOOP_MAX(5)보다 작다면 반복\
		근데 '++'이 붙어 있기때문에\
		loop_count는 반복마다 숫자가 1씨 증가하게 됩니다.

	// '++','--' 에는 전위 연산자와 후위 연산자 개념이 존재함.\
		전위 연산자의 경우 '++loop_count' 형태가 됩니다.\
		후위 연산자의 경우 'loop_count++' 형태입니다.\
		이 경우엔 조건이 먼저 비교되고 이후에 덧셈이 계산이 됩니다.
	while (loop_count++ < LOOP_MAX)
	{
		printf("loop_count = %d\n", loop_count);
		roll_dice();
		print_dice_number();
	}

	set_player_name("안녕");
	print_player_name();
	

	return 0;
	
}