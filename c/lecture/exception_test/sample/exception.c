#include "exception.h"

#include <stdio.h>

jmp_buf global_exception_buffer;

int divide_by_zero(int target, int number)
{
	printf("number = %d\n", number);

	if (number == 0) { longjmp(global_exception_buffer, DIVIDE_BY_ZERO); }

	return target / number;
}

bool array_index_exceed(int *array, int index, jmp_buf env)
{
	return false;
}

void exception_setup_table(void)
{
	// 사실상 여기서 goto label 지정하는 것임
	switch (setjmp(global_exception_buffer))
	{
		case DIVIDE_BY_ZERO:
			printf("현재 계산되는 입력값 중 0으로 처리되는 값이 존재합니다!\n");
			break;

		default:
			printf("사고 없음!\n");
			break;
	}
}

void just_test(void)
{
	// goto는 함수 Stack을 건너뛸 능력이 없음
	// goto error_handler;

	printf("test\n");
}