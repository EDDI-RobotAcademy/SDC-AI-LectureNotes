#include <stdio.h>
#include "print_even.h"

// define A B 라고 적는다면
// A를 B로 대체하겠음
// 그런데 대체하는 목적은 ?
// - 목적성을 명확하게 만들기 위해서 #define을 사용
// - 목적이 바뀌었을 때 해당하는 부분만 정확히 바꾸기 위해
//  ex) 공장에서 라인 5개 돌리다가 10개로 증설 했을 때 간단히 define에서 바꾸면 완료
// Q. const와 #define의 차이점은 ?
// const는 '출력' 값의 '불변성' 보장
// #define은 '일관성'을 유지하기 위해 사용
#define EVEN_DECISION_NUMBER	2

void print_even_number_from_start_to_end(int start, int end)
{
	// 현재 값이 얼마냐 ?
	int current_number;

	// start ~ end 까지 갈 것이므로
	// current_number = 시작(start)
	// 그리고 끝(end)를 포함해야 하므로 부등호를 '<=' 작거나 같다로 지정
	// current_number++ <<- 여기서 '++' 이라는 표현은 단순히 더하기 1을 의미함

	// - 기본적인 for 문의 동작 과정
	// for (초기설정; 조건; 증감) { 조건이 만족 할 때 무엇을 반복시킬 것인가 }
	// - 초기 설정: for 문을 만났을 때 최초 1번만 실행됨
	// - 조건: 조건이 만족할 경우 ('{}') 내부의 코드가 실행됨
	//		   만약 조건이 만족되지 않는다면 그대로 for문은 종결됨
	//		   조건이 만족되면 증감을 하지 않고 바로 중괄호 파트 실행
	// - 증감: 중괄호('{}') 파트가 실행된 이후 증감을 실행함

	// 초기 설정이나 증감이 없어도 조건만 만족한다면 for문은 동작
	for (current_number = start; current_number <= end; current_number++)
	{
		// - if 문의 동작 과정
		//	 소괄호 내부에 조건이 만족된다면 중괄호 코드를 실행
		//   조건이 만족되지 않는다면 제낀다..

		// current_number 나누기 EVEN_DECISION_NUMBER(2) 의 결과 나머지가 0이 맞나 ? 라는 조건
		if (current_number % EVEN_DECISION_NUMBER == 0)
		{
			// 위 조건이 만족하는 경우에만 printf 출력이 진행
			printf("이 번호는 짝수입니다: %d\n", current_number);
		}
	}
}

// 짝수: 2n
// 홀수: 2n + 1