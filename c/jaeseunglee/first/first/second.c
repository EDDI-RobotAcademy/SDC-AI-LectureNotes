// stdio.h = 표준 입출력, 
// printf()를 사용하려면 필요하다

#include <stdio.h>
#include "second.h"


//	void 뜻은 공허함, 텅 빈
// 
//	함수 작성 요령
// 
//	1. return 타입 정의
//	[리턴 타입이란 결론적으로 출력을 의미]
// 
//	2. 함수이름 작성(이름을 알기 쉽도록, 풀네임으로)
// 
//	3. 소괄호를 열고 닫은 후 파라미터(인자, 입력)타입을 작성

void second_function(void)
{
	// int 는 데이터타입
	// number는 변수 이름
	// 변수 = 메모리에 공간을 할당
	// => 특정 데이터타입의 공간에 정보를 저장
	// 데이터 타입 = int, float, double, short, long, long long int, long long double
	// int(4byte) float(4byte) double(8byte) short(2byte) char(1byte)

	// byte란?
	// 1byte = 8bit
	// bit = 0or1을 표현할 수 있는 단위
	// 1bit = 2 / 2bit = 4 / ... / 8bit = 1byte = 256 (2^8) => (0~255) / (-128~127)

	//	int, short, char, long long int 는 정수
	//	float, double, longlongdouble 은 실수
	//	char는 문자 또한 표현할 수 있음

	//	변수를 만드는 방법
	//	1. 데이터 타입 지정
	//	2. 변수의 이름 지정(목적과 의미를 확실하게)
	//	3. 필요하다면 변수를 초기화 (변수='숫자')

	//	주의사항 : '='은 대입 연산
	int number = 3;

	// %d == decimal 뒤에 오는 number를 표현
	printf("숫자 = %d\n", number);

}


void funcc(int a)
{
	if (a > 0)
	{
		for (a; a < 10; a++)
		{
			printf("%d\n", a);
		}
		printf("\n\n\n\n");
	}
}

