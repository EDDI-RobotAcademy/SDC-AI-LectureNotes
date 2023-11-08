#include <stdio.h>
#include "print_even_advanced.h"

// EVEN_DECISION이 매크로 함수가 된 것
// EVEN_DECISION(TARGET_NUMBER) 에서 TARGET_NUMBER는 실제 함수처럼 입력이 되었음
// ((TARGET_NUMBER) % 2 == 0 ) 는 입력을 2로 나눠서 나머지가 0인지 확인
// 0이면 True, 아니면 False

// EVEN_DECISION(TARGET_NUMBER)가 ((TARGET_NUMBER) % 2 == 0) 으로 치환됨
#define EVEN_DECISION(TARGET_NUMBER)		((TARGET_NUMBER) % 2 == 0)

void print_even_number_from_start_to_end_advanced(int start, int end)
{
	int current_number;

	for (current_number = start; current_number <= end; current_number++)
	{

		if (EVEN_DECISION(current_number))
		{
			printf("이 번호는 짝수입니다: %d\n", current_number);
		}
	}
}