#include <stdio.h>
#include "print_even.h"

// define A B 라고 적는다면
// A를 B로 대체하겠음을 의미합니다.
// 그런데 대체하는 목적이 무엇일까요?
// 목적성을 명확하게 만들기 위해서 #define을 사용합니다.

// Q. const와 #define의 차이
//		const는 출력 결과의 불변성 보장
//		#define은 일관성을 유지하기 위해
#define EVEN_DECISION_NUMBER 2

void print_even_number_from_start_to_end(int start, int end)
{
	//현재 값이 얼마냐?
	int current_number;
	
	//시작 - 끝까지 갈 것이므로
	//current_number = 시작(start)
	//current_number++ <- 여기서 '++'은 단순히 더하기 1을 의미한다

	// - 기본적인 for문의 동작과정
	//	for (초기설정; 조건; 증강) { 조건이 만족 할때까지 무엇을 반복시킬 것인지}
	// 
	// - 초기설정 : for문을 만났을 때 최초 1번만 실행됨
	// - 조건 : 조건이 만졸할 경우 중괄호('{ }') 내부의 코드가 실행됨
	//			만약 조건이 만족하지 않을 경우 그대로 for문을 빠져나온다
	//			조건이 만족되면 증감을 하지 않고 바로 중괄호 파트가 실행된다.
	// - 증감 : 중괄호('{ }') 파트가 실행된 이후 증감을 실행함
	
	//	초기 설정이니 증감이 없어도 조건만 만족한다면 for문은 동작한다.
	for (current_number = start; current_number <= end; current_number++)
	{
		// -if문의 동작 과정
		// 소괄호 내부에 조건이 만족된다면 중괄호 코드를 실행하며
		// 조건이 만족하지 않는다면 빠져나온다.
		// 
		// current_number 나누기 EVEN_DECISION_NUMBER은
		// 나머지 값이 0이 맞는가에 대한 조건문이다
		//
		if (current_number % EVEN_DECISION_NUMBER == 0)
		{
			printf("이 번호는 짝수입니다: %d\n", current_number);
		}
	}
}