#include "exception.h"

#include <stdio.h>

jmp_buf global_exception_buffer;

bool divide_by_zero(int target, int zero, jmp_buf env)
{
	return false;
}

bool array_index_exceed(int *array, int index, jmp_buf env)
{
	return false;
}

void just_test(void)
{
	// goto는 함수 Stack을 건너뛸 능력이 없음
	// goto error_handler;

	printf("test\n");
}