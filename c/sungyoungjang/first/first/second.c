// stdio => Standard IO의 약자
// printf() 를 사용하려면 #include<stdio.h>가 필요.
#include <stdio.h>
#include "second.h"

// void의 영어 의미는 '공허한', '텅빈'
// 함수를 작성하는 요령
//
//1. 먼저 return 타입을 작성.
//	[return 타입이란 결론적으로 출력을 의미.]
//2. 함수의 이름 작성.(자유롭게 작성) <- 어떤 작업인지 의미 전달이 쉽게 작성.
//  [약자로 이름을 지으면 혼선이 발생 할 수 있으므로 풀 네이밍으로 작성!]
//3. 소괄호를 열고 닫은 이후 파라미터(인자 혹은 입력) 타입을 작성.

void second_function(void)
{
	// int number
	
	// int 라는 것은 데이터타입
	// number는 변수의 이름
	// Q. 변수는 무엇일까?
	// 1. 값을 대입할수 있는것
	// 2. 임의대로 변경가능한 정보
	// 3. 메모리 공간을 할당
	// => 특정한 데이터타입의 메모리 공간에 정보를 저장
	//  데이터 타입 => int, float, double, short, byte, long, long long int, long long double
	// int(4byte), float(4byte), double(8byte), short(2byte), char(1byte) 

	// byte 란 무엇인가?
	// bit 라는 개념이 존재하며 bit가 8개가 모이면 1byte가 된다.
	// bit는 0 또는 1을 표현하는 단위
	// 1bit면 표현 가능한 숫자가 2개 (2^1)
	// 2bit면 표현 가능한 숫자가 4개 (2^2)
	// 3bit면 표현 가능한 숫자가 8개 (2^3)
	// 8bit (1Byte) => 2^8 => 256 => (0~255 양수), (-128~-127 음수 고려)

	// int,short, char, long long int는 모두 정수 (-300,0,90,-400, 등등)
	// float, double, long long double은 모두 소수점(-0.3, 0.111, 등등)
	// char는 문자 또한 표현 할 수있다.
	
	//변수를 만드는 방법
	// 1. 데이터 타입을 작성.
	// 2. 변수 이름을 지정.(목적 및 의미 전달이 잘되도록.)
	// 3. 필요하다면 변수를 초기화합니다. (초기화는 '=숫자'형태로 가능)
	// 
	// 주의사항 '=' 은 대입연상 (1=1 같다 같은 것이 아니라 a = 1 같은 것)
	//
	int number = 3;
	// %d  decimal의 약자로 number 라는 값을 초기화 한다.
	printf("숫자 = %d\n", number);
}