#include <stdio.h>
#include "print_even.h"
#include "print_even_advanced.h"
#include "print_random.h"
#include "dice_game.h"
#include "random_dice.h"
#include "player.h"

#define LOOP_MAX  5

int main(void)
{	
	const int random_number_count = 10;
	const int start = 3;
	const int end = 13; 
	const int dice_roll = 5;

	int loop_count = 0;
	// 시작 ~ 끝 사이의 숫자에서 짝수를 출력 
	print_even_number_from_start_to_end(start,end);
	printf("\n");
	
	printf("조금 더 개선한 코드!\n");
	print_even_number_from_start_to_end_advanced(start, end);
	printf("\n");

	//random 숫자 10개 출력하기 
	print_random_number(random_number_count);
	printf("\n");

	//주사위 굴리기 
	print_random_dice(dice_roll);
	printf("\n");

	printf("조금 더 개선한 주사위 코드!\n");
	// while 문은 for 문과 마찬가지로 반복문 중 하나입니다. 
	// 보편적으로 for는 약간 복잡한 구조에서 많이 사용하는 편이고 while은 단순히 뺑뻉이 돌릴려고 하면 사용하는 편이다.
	// 물론 관습적인 부분이기 때문에 꼭 저렇게 할 필요는 없음. 

	// - while의 동작 과정 
	//	조건 비교는 if와 동일하다 
	//	소괄호 내의 조건을 만족하면 반복이 된다. 
	//	소괄호 내의 조건을 만족하지 못하면 반복이 중단됨. 
	 
	// loop_count가 LOOP_MAX(5) 보다 작다면 반복 
	// 근데 '++'이 붙어 있기 때문에 loop_count는 반복마다 숫자가 1씩 증가하게 된다.  
	while (loop_count++ < LOOP_MAX)
	{
		printf("loop_count = %d\n", loop_count);
		roll_dice();
		print_dice_number();
	}
	
	printf("\n");

	set_player_name("박성환");
	print_player_name();
	return 0;
}

// '++',  '--'에는 전위 연산자와 후위 연산자 개념이 존재함 
// 전위 연산자의 경우 '++ loop_count'형태가 된다. 
// 이 경우에는 아래 조건이 비교 되기 이전에 먼저 덧셈이 계산됨. 
// 후위 연사자의 경우 'loop_count++ '형태가 된다. 
// 이 경우에는 조건이 먼저 비교되고 이후에 먼저 덧셈이 계산됨. 