//stdio => Standard IO의 약자
//printf() 를 사용하려면#include <stdio.h> 가 필요합니다.
#include <stdio.h>
#include "second.h"

//함수를 작성하는 요령
//1. 먼저 return(리턴) 타입을 작성합니다.
//	[ 리턴 타입이란 결론적으로 출력을 의미합니다.	] -> return * -> 값이 *으로 나온다.
//2. 함수의 이름을 작성합니다 (자유롭게 작성) <- 어떤 작업인지 의미 전달이 쉽게 이름을 작성합니다.
//	[ 약자로 이름을 지으면 혼선이 발생 할 수 있으므로 풀 네이밍으로 작성합시다!	]
//3. 소괄호를 열고 닫은 이후 파라미터(인자 혹은 입력) 타입을 작성합니다.
void second_function(void)
{
	//변수란 무엇인가?
	// 메모리 공간을 할당
	// => 특정한 데이터타입의 메모리 공간에 정보를 저장
	// 데이터 타입 => int, float, double, short, char, long, long long int, long long double
	// int(4byte), float(4byte), double(8byte), short(2byte), char(1byte)

	// byte란 무엇인가?
	// bit라는 개념이 존재하며 이 bit가 8개 모이면 1byte가 됩니다.
	// bit란 무엇인가?
	// bit는 0 혹은 1을 표현할 수 있는 단위
	// 1bit면 표현 가능한 숫자가 2개 (2^1)
	// 2bit면 표현 가능한 숫자가 4개 (2^2)
	// 3bit면 표현 가능한 숫자가 8개 (2^3)
	// 8bit(1byte) => 2^8 => (0~255 양수), (-128~127 음수 고려)
	// 정수값 : int, short, char, long long int
	// 소수값포함 : float, double, long long double
	// char은 문자로도 가능
	
	int number = 3;
	printf("숫자 = %d\n", number);

}