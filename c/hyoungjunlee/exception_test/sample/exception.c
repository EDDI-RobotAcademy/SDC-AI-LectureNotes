#include "exception.h"

#include <stdio.h>
#include <stdlib.h>

jmp_buf global_exception_buffer;

int divide_by_zero(int target, int number)
{
	printf("number = %d\n", number);

	if (number == 0) { longjmp(global_exception_buffer, DIVIDE_BY_ZERO); }

	return target / number;
}

typedef struct _test_array test_array;
struct _test_array
{
	int max_count;
	int *array;
};

bool array_index_exceed(int index)
{
	test_array test_array_for_exception;
	test_array_for_exception.max_count = 6;
	test_array_for_exception.array = (int *)malloc(sizeof(int) * 6);

	if (index > test_array_for_exception.max_count)
	{
		longjmp(global_exception_buffer, ARRAY_INDEX_EXCEED);
	}

	printf("결과 출력: %d\n", test_array_for_exception.array[index]);

	return false;
}

void exception_setup_table(void)
{
	// 사실상 여기서 goto label 지정하는 것임
	switch (setjmp(global_exception_buffer))
	{
		case DIVIDE_BY_ZERO:
			printf("현재 계산되는 입력값 중 0으로 나누기를 하고 있습니다!\n");
			break;

		case ARRAY_INDEX_EXCEED:
			printf("배열의 인덱스 한도를 초과하셨습니다!\n");
			break;
	}
}

void just_test(void)
{
	// goto는 함수 Stack을 건너뛸 능력이 없음
	// goto error_handler;

	printf("test\n");
}