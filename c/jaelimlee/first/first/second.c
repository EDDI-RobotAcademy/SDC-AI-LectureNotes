// stdio-> Standard IO의 약자 (표준 입출력)
// printf()를 사용하려면 #include <stdio.h> 가 필요함
#include <stdio.h>
#include "second.h"

// void -> 영어 의미는 '공허한', '텅빈'
// 함수를 작성하는 요령을 파악해야 함
// 1. 먼저 return 타입을 작성
//    [리턴 타입이란 결론적으로 출력을 의미]
// 2. 함수의 이름을 작성(자유롭게 작성) <- 어떤 작업인지 의미 전달이 쉽게 이름을 작성
//    [약자로 이름을 지으면 혼선이 발생할 수 있으므로 풀 네이밍으로 작성]
// 3. 소괄호를 열고 닫은 이후 파라미터(인자 혹은 입력) 타입을 작성
void second_function(void)
{
	//int -> 데이터 타입
	// number -> 변수의 이름
	// Q. 변수란 무엇일까? 
	// => 특정한 데이터 타입의 메모리 공간에 정보를 저장
	// 데이터 타입=> int, float, double, short, char, byte, long, long long int, long long double
	// int(4byte), float(4byte), double(8byte), short(2byte), char(1byte)

	// byte란 무엇인가?
	// -> bit라는 개념이 존재. bit가 8개9 모이면 1byte
	// bit란 무엇인가?
	// -> 0 혹은 1을 표현할 수 있는 단위
	// 1bit면 표현 가능한 숫자 2개
	// 2bit면 표현 가능한 숫자 4개
	// 3bit면 표현 가능한 숫자 8개
	// 8bit면 표현 가능한 숫자 256개(2^8)-> (0 - 255 양수기준), (-128 - 127 음수 고려)

	// int, short, char, long long int는 모두 정수(-300, 0, 90, -400, 123등)
	// float, double, long long double은 모두 소수점9-0.3, 0.111, 0.948, -0.7283등)
	// char는 문자 또한 표현 가능 

	// 변수를 만드는 방법
	// 1. 데이터 타입을 작성
	// 2. 변수 이름 지정(목적 및 의미 전달이 잘 되어야 함)
	// 3. 필요하다면 변수를 초기화 함(초기화는 '=숫자' 형태로 가능)
	int number = 3;
	// %d-> decimal의 약자. number 라는 값을 숫자 형태로 표현해줌. 
	printf("숫자 = %d\n", number);
}