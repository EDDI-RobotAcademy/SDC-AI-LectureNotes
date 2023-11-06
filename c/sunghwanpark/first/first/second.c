// stdio -> Standard I0 의 약자 
// printf() 를 사용하려면 #include <stdio.h> 가 필요합니다. 
#include <stdio.h>
#include "second.h"

//void의 영어 의미는 '공허한, 텅 빈'
// 함수를 작성하는 요령
// 1. 먼저 return 타입을 작성합니다.
//    [return 타입이란 결론적으로 출력을 의미합니다.]
// 2. 함수의 이름을 작성합니다 (자유롭게 작성) <- 어떤 작업인지 의미 전달이 쉽게 이름을 작성합니다. 
//    [약자로 이름을 지으면 혼선이 발생 할 수 있으므로 풀 네이밍으로 작성합시다!]
// 3. 소괄호를 열고 닫은 이후 parameter (인자 혹은 입력) 타입을 작성합니다. 

void second_function(void)
{	
	//int number -> int 는 data type, number는 변수의 이름 
	// 변수란? 
	// -> 특정한 데이터 타입의 메모리 공간 에 정보를 저장 
	// data type -> int, float, double, short, byte, long, long long int, long long double 
	// int (4 byte), float (4 byte), double (8 byte), short (2 byte), char (1  byte)

	//byte란 무엇인가? 
	// bit라는 개념이 존재하며 bit 가 8개 모이면 1byte가 됩니다. -> 8 bit = 1 byte
	// bit 란 무엇인가? 
	// bit는 0 혹은 1 을 표현할 수 있는 단위 
	// 1 bit면 표현 가능한 숫자가 2개 (2^1), 2 bit면 표현 가능한 숫자가 2개 (2^2), 3 bit면 표현 가능한 숫자가 2개 (2^3)
	// 8 bit (1 byte) -> 2^8 = 256 -> (0 ~ 255 양수), (-128 ~ 127 음수 고려) 

	// int, short, char, long long int 는 모두 정수 (-300,0,90,-400,123 등등) 
	// float, double, long long double 은 모두 소수점 (-0.3, 0.111,0.948,-0.728 등등) 
	// char는 문자 또한 표현 할 수 있습니다. 

	// 변수를 만드는 방법 
	// 1. 데이터 타입을 작성합니다.
	// 2. 변수 이름을 지정합니다. (목적 및 의미 전달이 잘 되어야 합니다.)
	// 3. 필요하다면 변수를 초기화 합니다. (초기화는 '=숫자' 형태로 가능합니다)  

	// 주의 사항 '=' 은 대입 연산으로 생각해주세요 (같은게 아닙니다.) 
	int number = 3;

	//%d는 decimal의 약자로 number 라는 값을 숫자 형태로 표현해줍니다. 
	printf("숫자 = %d\n", number);
}