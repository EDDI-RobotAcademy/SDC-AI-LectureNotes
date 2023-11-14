#include <stdio.h>
#include "even_number.h"

// define A B 라고 적는다면
// A를 B로 대체하겠음을 의미합니다.
// 그런데 대체하는 목적이 무엇일까요 ?
// 목적성을 명확하게 만들기 위해서 #define을 사용합니다.

// Q. const와 #define의 차이가 무엇인가요 ?
//    const는 출력 결과의 불변성을 보장합니다.
//    #define은 일관성을 유지하기 위해 사용합니다.
#define EVEN_ROLL_NUMBER			2

void print_even_number_from_start_to_end(int start, int end)
{
	// 현재 값이 얼마냐 ?
	int current_number;

	for (current_number = start; current_number <= end; current_number++)
	{
		// - if 문의 동작 과정
		//   소괄호 내부에 조건이 만족된다면 중괄호 코드를 실행하며
		//   조건이 만족되지 않는다면 제낍니다.
		
		// current_number 나누기 EVEN_DECISION_NUMBER (2) 의 결과
		// 나머지가 0이 맞나요 ? 라는 조건을 가지고 있습니다.
		if (current_number % EVEN_ROLL_NUMBER == 0)
		{
			// 위 조건이 만족하는 경우에만 printf 출력이 진행됩니다.
			printf("이 번호는 짝수입니다: %d\n", current_number);
		}
	}
}

