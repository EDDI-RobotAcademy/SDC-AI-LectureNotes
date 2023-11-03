#include <stdio.h>
// 아래의 second_functio() 을 사용하기 위해 헤더 파일을 include 함
#include "second.h"
#include "forth.h"

int main(void)
{
	// printf는 말 그대로 소괄호 내부에 있는 문자열을 출력
	// 문자열은 "" 사이에 문장을 집어 넣는 형식으로 구성
	// "\n" 은 enter키의 역할을 수행
	printf("Hello First C Programming!\n");
	
	// second_function 은 두 번째 작업이라는 뜻
	// 외부에 있는 함수를 사용할 때에는 *.c 파일과 *.h 파일을 같이 작성해야 함
	// 사용할 때에는 함수의 이름을 작성하고 소괄호를 열고 닫아야 함
	second_function();

	// Q. forth_function에서 숫자 7을 출력하도록 만들어봅시다!
	forth_function();

	return 0;
}
/*
#ifdef 0

void 속도제어()
{
	// 속도 제어를 전압으로 한다 가정
	float voltage = aquire_voltage_from_adc_sensor();
	// 전압 값을 토대로 pid 값을 조정 (덧셈 및 곱셈, 적분, 미분)
	pid_t* pid_struct = adjust_pid_control_structure();
	// 실질적인 속도 제어
	control_velocity(pid_struct);
}
*/

