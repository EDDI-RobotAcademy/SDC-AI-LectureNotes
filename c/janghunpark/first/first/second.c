// stdio => standard IO의 약자
// printf()를 사용하려면 #include <stdio.h> 가 필요
#include <stdio.h>
#include "second.h"

// void의 영어 의미 = 공허한, 텅 빈
// 함수를 작성하는 요령
// 1. 먼저 return(리턴) 타입을 작성
//    [ 리턴 타입이란 결론적으로 출력을 의미 ]
// 2. 함수의 이름 작성; 어떤 작업인지 의미 전달이 쉽게 이름을 작성
//    [ 약자로 이름을 지으면 혼선이 발생될 수 있으므로, 풀 네이밍으로 작성하기 ]
// 3. 소괄호를 열고 닫은 이후 파라미터(인자) 타입을 작성
void second_function (void)
{
	// int number
	// int 는 데이터 타입
	// number 는 변수의 이름
	// 변수란 무엇일까? "메모리 공간을 할당하는 것, 특정한 데이터 타입의 메모리 공간"
	// 데이터 타입 ==> int(4), float(4), double(8), short(2), char(1), byte, long, long long int, long long double
	
	// byte란? 
	// 8 bit = 1 byte
	// bit란?
	// bit는 0 혹은 1을 표현할 수 있는 단위
	// 따라서 1 bit = 숫자 2개 표현, bit가 올라갈 수록 2의 n승으로 경우의 수 표현
	// 1byte = 256 => 0 - 255 양수, 음수 표현?

	// int, short, char, long long int 는 모두 정수
	// float, double, long long double 은 모두 소수점
	// char는 문자도 표현 가능 (아스키 코드)

	// 변수를 만드는 방법
	// 1. 데이터 타입을 작성
	// 2. 변수 이름 지정 (목적 및 의미 전달 신경쓰기)
	// 3. 필요 시 변수를 초기화 (초기화는 '=숫자' 형태로 가능)
	
	// 주의사항 '='는 대입 연산임 (같다라는 의미가 아님) 
	int number = 3;
	// %d decimal 의 약자로 number 라는 값을 숫자 형태로 표현
	printf("숫자 = %d\n", number);
	int addnum = 10;
	printf("추가 = %d\n", addnum);
}