#include <stdio.h>
// 아래의 second_function() 을 사용하기 위해 헤더 파일을 include 하였습니다.
#include "second.h"
#include "third.h"
#include "fourth.h"

int main(void)
{
	int return_value;
	// printf는 말 그대로 소괄호 내부에 있는 문자열을 출력합니다.
	// 문자열은 "" (쌍따옴표) 사이에 문장을 집어넣는 형식으로 구성됩니다.
	// '\n' 은 개행문자 (엔터) 의 역할을 수행합니다.
	printf("Hello First C Programming!\n");

	// second_function 두 번째 작업이다라는 의미로 작성하였음
	// 외부에 있는 함수를 사용할 때는 *.c 파일과 *.h 파일을 같이 작성해야 합니다.
	// 사용할 때는 함수의 이름을 작성하고 소괄호를 열고 닫아야 합니다.
	second_function();
	return_value = third_function();
	printf("return_value = %d\n", return_value);
	// Quiz, fourth_function에서 숫자 7을 출력하도록 만들어 봅시다.
	fourth_function();

	return 0;
}

//#ifdef 0
//void 속도제어()
//{
//	// 속도 제어를 전압으로 한다 가정
//	float voltage = acquire_voltage_from_adc_sensor();
//	// 전압 값을 토대로 pid값을 조정 (덧셈 및 곱셈, 적분, 미분)
//	pid_t* pid_struct = adjust_pid_control_structure();
//	// 실질적인 속도 제어
//	control_velocity(pid_struct);
//}
//#endif
