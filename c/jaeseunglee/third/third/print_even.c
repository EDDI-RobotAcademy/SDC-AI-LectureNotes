#include <stdio.h>
#include "print_even.h"


// #define A B -> A를 B로 대체하겠음
// 대체하는 목적
// 1. 목적성을 명확하게 만들기 위해
// 2. 통합 관리를 용이하게 하기 위해
// 전역변수는 프로세스간 정보공유를 위해 쓰지만
// #define은 프로세스간 정보공유는 없음
// 
// const는 출력결과의 불변성을 보장
// #define은 일관성을 유지하기 위해 사용

// #define 런타임중에 동작하는 것이 아닌 컴파일 단계에서 계산이 되어있음
// #define은 따로 함수를 만드는 것 보다 동작이 빠름

// #define의 type은 auto
// #define의 type을 정하고 싶은 경우
// #define A (type)B

#define EVEN_DECISION_NUMBER 2

void print_even_number_from_start_to_end(int start, int end)
{
	
	// 현재 값이 얼마인지 파악하기 위해 선언
	int current_number;
	
	// 시작 ~ 끝까지 갈 것이므로
	// current_number = 시작(start)
	// 그리고 끝(end)를 포함해야 하므로 부등호를 '<=' 작거나 같다로 지정
	// current_number++ << 여기서 '++'이라는 표현은 단순이 더하기 1을 의미
	
	// - 기본적인 for 문의 동작 과정
	// for(초기설정;조건;증감) { 조건이 만족 할 때 반복시킬 내용 }
	
	// - 초기 설정: for 문을 만났을 때 최초 1번만 실행
	// - 조건: 조건이 만족 할 경우 중괄호('{}') 내부의 코드가 실행됨
	//		   만약 조건이 만족되지 않는다면 그대로 for문은 종결
	//         조건이 만족되면 증감을 하지 않고 바로 중괄호 파트가 실행
	// - 증감: 중괄호('{}') 파트가 실행 된 이후 증감을 실행

	// 초기 설정이나 증감은 없어도 조건만 만족한다면 for문은 동작함.
	for (current_number = start; current_number <= end; current_number++)
	{
		// - if문의 동작 과정
		//	 소괄호 내부의 조건이 만족된다면 중괄호 코드를 실행하며
		//   조건이 만족되지 않는다면 pass

		// current_number 나누기 EVEN_DECISION_NUMBER (2) 의 결과
		// 나머지가 0이 맞나요? 라는 조건을 포함
		if (current_number % EVEN_DECISION_NUMBER == 0)
		{
			// 위 조건이 만족하는 경우에만 printf 출력이 진행
			printf("%d는 짝수입니다.\n", current_number);
		}
	}

	
	
	
	printf("\n");
}


// 짝수: 2n		-> n%2 == 0
// 홀수: 2n+1	-> n%2 == 1