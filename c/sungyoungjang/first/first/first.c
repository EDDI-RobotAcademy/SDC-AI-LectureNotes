#include <stdio.h>
// 아래의 second_function() 을 사용하기 위해 헤더파일을 include 하였다.
#include "second.h"
#include "fourth.h"

int main(void)
{
	int return_value;
	// prinf는 말그대로 소괄호 내부에 있는 문자열을 출력.
	// 문자열은 "" 사이에 문장을 집어넣는 형식으로 구성.
	// '\n' 은 개행 문자 (엔터) 의 역할을 수행.
	printf("Hello First C Programming!\n");

	// second_function 두 번째 작업이라든 의미로 작성.
	// 외부에 있는 함수를 사용할 때는 *.c 파일과 *.h 파일을 같이 작성.
	// 사용할 때는 함수의 이름을 작성하고 소괄호를 열고 닫아야한다.
	second_function();
	fourth_function();
		// Q. fourth_function에서 숫자 7을 출력하도록 만들어봅시다.



	return 0;
}
