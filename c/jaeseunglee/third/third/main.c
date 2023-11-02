#include <stdio.h>
#include "print_even.h"
#include "print_even_advanced.h"
#include "print_random.h"
#include "random_generator.h"
#include "dice.h"

#include "dice_game.h"

#define LOOP_MAX 5

int main(void)
{
	const int start = 3;
	const int end = 13;
	const int random_number_count = 10;

	int loop_count = 0;
	// 시작 - 끝 사이의 숫자에서 짝수를 출력
	print_even_number_from_start_to_end(start, end);

	printf("조금 더 개선한 코드!\n\n");

	print_even_number_from_start_to_end_advanced(start, end);

	print_random_number(random_number_count);

	printf("\n\n\n");

	

	printf("주사위를 굴립니다. 데굴데굴 : %d\n",roll_the_dice());

	printf("\n");

	dice_fight(generate_random(0, 255), generate_random(0, 255));

	printf("\n\n\n");

	// while 문은 for문과 마찬가지로 반복문
	// 보편적으로 for는 약간 복잡한 구조에서 많이 사용
	// while은 단순히 반복시킬때 주로 사용
	// 관습적인 부분이기에 반드시 그럴 필요는 없음

	// -while의 동작 과정
	//  조건 비교는 if와 동일
	//  소괄호 내의 조건을 만족하면 반복 시행
	//  조건을 만족하지 못하면 중단

	// loop_count가 LOOP_MAX(5)보다 작다면 반복
	// 근데 ++이 붙어있기 때문에 loop_count는 반복마다 숫자가 1씩 늘어남

	// '++' '--' 에는 전위 연산자와 후위 연산자 개념이 구별됨
	// 전위 연산자의 경우 '++loop_count' 형태
	// 이 경우엔 조건 비교 전에 덧셈이 계산됩니다.
	// 후위 연산자의 경우 'loop_count++'형태
	// 이 경우엔 조건 비교 후에 덧셈이 계산됩니다.
	while (loop_count++ < LOOP_MAX)
	{
		
		roll_dice();
	
		print_dice_number();
	}
	
	

	return 0;

}