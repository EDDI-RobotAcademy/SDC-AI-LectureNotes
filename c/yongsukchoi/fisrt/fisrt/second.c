// stdio => Standard IO 의 약자
// printf() 를 사용하려면 #include <stdio.h> 가 필요합니다.
#include <stdio.h>
#include "second.h"

// void의 영어 의미는 '공허한, 텅빈'
// 함수를 작성하는 요령
// 
// 1. 먼저 return (리턴) 타입을 작성합니다.
// [리턴 타입이란 결론적으로 출력을 의미합니다.]
// 2. 함수의 이름을 작성합니다 (자유롭게 작성) <- 어떤 작업인지 의미 전달이 쉽게 이름을 작성합니다.
// [ 약자로 이름을 지으면 혼선이 발생 할 수 있으므로 풀 네이밍으로 작성합니다! ]
// 3. 소괄호를 열고 닫은 이후 파라미터(인자 혹은 입력) 타입을 작성합니다.
void second_function(void) {
	// int number
	// int 라는 것은 데이터타입
	// number는 변수의 이름
	// 그렇다면 변수란 무엇일까요?
	// 3. 메모리 공간을 할당
	// => 특정한 데이터타입의 메모리 공간에 정보를 저장
	// 데이터 타입 => int, float, double, short, byte, long, long long int, long long double
	// int (4byte), float (4byte), double (8byte), short (2byte), char (1byte)

	// byte란 무엇인가 ?
	// bit라는 개념이 존재하며 이 bit가 8개 모이면 1byte가 됩니다.
	// bit란 무엇인가?
	// bit는 0 혹은 1을 표현할 수 있는 단위
	// 1bit면 표현 가능한 숫자가 2개
	// 2bit면 표현 가능한 숫자가 4개
	// 3bit면 표현 가능한 숫자가 8개 
	// 8bit (1byte) => 2^8 => 256 => (0 ~ 255 양수), (-128 ~ 127 음수 고려)

	// int, short , char, long long int 는 모두 정수 (-200, 0, 90, -400, 123 등등)
	// float, double, long long double은 모두 소수점 (-0.3, 0.111 등등)
	// char는 문자 또한 표현 할 수 있습니다 <= 요 부분은 내일 한 번 살펴보겠습니다.

	// 주의 사항 = 은 대입연산으로 생각해주세요
	int number = 3;
	printf("숫자 = %d\n", number);
}