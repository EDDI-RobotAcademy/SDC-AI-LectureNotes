#include <stdio.h>
#include "print_even.h"
#include "print_even_advanced.h"
#include "print_random.h"

int main(void)
{
	const int random_number_count = 10;
	const int start = 3;
	const int end = 13;

	// 시작 ~ 끝 사이의 숫자에서 짝수를 출력
	print_even_number_from_start_to_end(start, end);

	printf("조금 더 개선한 코드!\n");
	print_even_number_from_start_to_end_advanced(start, end);

	// random 숫자 10개 출력하기
	print_random_number(random_number_count);

	return 0;
}