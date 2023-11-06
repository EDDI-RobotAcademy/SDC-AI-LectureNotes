#include <stdio.h>
#include "print_even.h"
#include "print_even_advanced.h"
#include "print_random.h"
#include "dice_game.h"

#define LOOP_MAX		3

int	main(void)
{
	const int random_number_count = 10;
	const int start = 3;
	const int end = 13;

	int loop_count = 0;

	printf("The Original Version\n");
	print_even_number_from_start_to_end(start, end);
	printf("The Upgraded Version\n");
	print_even_number_from_start_to_end_advanced(start, end);

	// random number 10개 출력
	print_random_number(random_number_count);
	printf("\n");

	/*
	while 문은 for 문과 마찬가지로 반복문 중 하나
	보편적으로 for 는 약간 복잡한 구조에서 많이 사용
	while 은 단순히 뺑뺑이 돌리려고 사용
	관습적인 부분이라 꼭 그렇게 할 필요는 없음

	while의 동작 과정
	1. 조건 비교는 if와 동일
	2. 소괄호 내의 조건을 만족하면 반복
	3. 소괄호 내의 조건을 만족 못 하면 반복 중단

	loop_count가 LOOP_MAX(3) 보다 작다면 반복
	근데 '++'이 붙어 있으므로 loop_count는 반복마다 숫자가 1씩 증가

	'++', '--' 에는 전위 연산자 vs 후위 연산자 개념 존재
	전위 연산자의 경우 '++loop_count' 형태
	이 경우엔 아래 조건이 비교 되기 전에 덧셈이 먼저 계산
	후위 연산자의 경우 'loop_count++' 형태
	이 경우엔 조건이 먼저 비교되고 연산 시작
	*/
	while (loop_count++ < LOOP_MAX)
	{
		printf("loop_count = %d\n", loop_count);
		roll_dice();
		print_dice_number();
		printf("extern이 어쨌다고? = %d\n", dice_number);
	}

	return 0;
}