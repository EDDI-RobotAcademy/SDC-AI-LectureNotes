#include <stdio.h>
//아래의 second_function()을 헤더파일로
#include "second.h"

int main(void)
{
	printf("Hello First C Programming!\n");

	//second_function 두 번째 작업이다라는 의미로 작성하였음
	//외부에 있는 함수를 사용할 떄는 *.c 파일과 *.h 파일을 같이 작성해야 합니다.
	// 사용할 때는 함수의 이름을 작성하고 소괄호를 열고 닫아야 합니다.
	second_function();

	//Quiz. fourth_function에서 숫자 7을 출력하도록 만들어봅시다!
	fourth_function();

	return 0;
}

/*
{
	float voltage = acquire_voltage_adc_sensor();
	pid_t* pid senc
}
#endif
*/