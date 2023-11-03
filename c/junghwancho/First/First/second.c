// stdio => Standard IO 의 약자
// printf()를 사용하려면 #include <stdio.h> 필요
#include <stdio.h>
#include "second.h"

// void 의 의미는 '공허, 텅 빈'
// 함수를 작성하는 요령
// 1. 먼저 return 타입을 작성
//    [리턴 타입이란 결론적으로 출력을 의미]
// 2. 함수의 이름을 작성 (자유롭게) <- 어떤 작업인지 의미 전달 가능하게
//    [약자로 작성하는 것 지양]
// 3. 소괄호를 열고 닫은 이후 파라미터(인자, 입력) 타입 작성
void second_function(void)
{
	// int number
	// int 라는 것은 데이터 타입
	// number는 변수의 이름
	// Q. 변수란 ?
	// 1. 뭔가 값을 대입할 수 있는 것
	// 2. 임의대로 변경 가능한 정보
	// 3. 메모리 공간을 활당
	// => 특정한 데이터 타입의 메모리 공간에 정보를 저장
	// 데이터 타입 => int, float, double, short, char, long, long long int, long long double
	// int (4byte), float (4byte), double (8byte), short (2byte), char (1byte)
	// 8 bit = 1 byte, 0 혹은 1을 표현할 수 있는 단위
	// x bit = 2^x 만큼 표현 가능 => 1byte = 2^8 = 256 (0~255, -128~127)
	// int, short, char, long long int는 모두 정수 (-300, 0, 90, -400, 123 등등)
	// float, double, long long double은 모두 소수점
	// char 는 문자 또한 표현 가능

	// 변수를 만드는 방법
	// 1. 데이터 타입 작성
	// 2. 변수 이름 지정 (목적 및 의미 전달)
	// 3. 필요하다면 변수 초기화 (초기화 = '숫자' 형태)
	// 주의 사항 '=' 은 대입(저장) 연산 (not equal)
	int number = 3;
	// %d = decimal의 약자로 number라는 값을 숫자 형태로 표현
	printf("숫자 = %d\n", number);
}