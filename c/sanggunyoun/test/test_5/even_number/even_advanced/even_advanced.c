#include <stdio.h>
#include "even_advanced.h"


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