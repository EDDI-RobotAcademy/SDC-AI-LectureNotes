#include <stdio.h>
// 아래의 second_function() 을 사용하기 위한 헤더 추가
#include "second.h"

int main(void)
{
	// printf = 소괄호 내부 문자열 출력
	// 문자열은 "" 사이에 문장을 집어 넣음
	// '\n'은 개행 문자 (엔터) 역할
	printf("Hello First C Programming!\n");

	// second_function 두 번째 작업이다라는 의미로 작성(임의로)
	// 외부에 있는 함수를 사용할 때는 *.c 파일과 *.h 파일을 같이 작성
	// 사용할 때는 함수의 이름을 작성하고 소괄호 여닫
	second_function();

	return 0;
}

// fourth_function에서 숫자 7을 출력하도록 만들기
