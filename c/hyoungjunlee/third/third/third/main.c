#include <stdio.h>
#include "print_even.h"
#include "print_even_advanced.h"
#include "print_random.h"
#include "random_generator.h"
#include "dice_game.h"
#define LOOP_MAX		5
int main(void)
{
	const int random_number_count = 10;
	int loop_count = 0;
	
	const int start = 3;
	const int end = 13;
	// 시작 -끝 사이의 숫자에서 짝수를 출력 밑의 함수의 목적
	print_even_number_from_start_to_end(start, end);

	printf("조금더 개선한 코드\n");
	print_even_number_from_start_to_end_advanced(start, end);

	//random 숫자 10개 출력하기
	print_random_number(random_number_count);

	//random_dice(random_number_count);
	
	//while문은 for문과 마찬가지로 반복문 중 하나 입니다
	//보편적으로 for는 약간 복잡한 구조에서 많이 사용하는 편이고
	// while은 단순히 뻉뺴이 돌릴려고 하면 사용하는 편입니다

	// -while의 동작과정
	//  조건 비교는 if와 동일합니다
	//  소괄호 내의 조건을 만족하면 반복이 됩니다
	//  소괄호 내의 조건을 만족하지못하면면 반복이 중단됩니다

    //loop_count가 LOOP_MAX(5) 보다 작다면 반복
	// 근데 '++'이 붙어있기 때문에
	//loop_count는 반복마다 숫자가 1씩 증가하게 됩니다
	// 
	// '++','--'에는 전위 연산자와 후위 연산자 개념이 존재함
	// 전위 연산자의 경우 '++loop count' 형태입니다
	// 이 경우엔 아래 조건이 비교 되기 이전에 먼저 덧셈이 계산됩니다
	// 후위 연산자의 경우 'loop count++' 형태입니다
	// 이경우엔 조건이 먼저 비교되고 이후에 덧셈이 계산됩니다
	while (loop_count++ < LOOP_MAX)
	{
		roll_dice();
		print_dice_number();
	}
	

	return 0;

}