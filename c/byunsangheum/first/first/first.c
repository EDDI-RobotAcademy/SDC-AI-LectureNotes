#include <stdio.h>
#include "second.h"
#include "fourth.h"

int main(void)
{

	printf("Hello First C Programming!\n");

	// second_function 두 번째 작업이다라는 의미로 작성하였음
	// 외부에 있는 함수를 사용할 때는 *.c 파일과 *.h 파일을 같이 작성해야 합니다.
	// 사용할 때는 함수의 이름을 작성하고 소활호를 열고 닫아야 합니다.
	second_function();
	fourth_function();
	


	// Quiz. fourth_function에서 숫자 7을 출력하도록 만들어봅시다.
	return 0;
}

/*
void 속도제어()
{
	// 속도 제어를 전압으로 한다 가정
	float voltage = acqurire_vlatage_form_adc_sencor();
	// 전압 값을 토대로 pid 값을 조정 (덧셈 및 곱셈, 적분, 미분)
	pid_t* pid_struct = adjust_pid_control_structure();
	// 실질적인 속도 제어

}
#endif // DEBUG
*/