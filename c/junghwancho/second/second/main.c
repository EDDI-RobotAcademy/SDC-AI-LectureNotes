#include <stdio.h>

// 출력 : int
// 입력 : int number
// 함수이름 : for_assembly_function_test
int for_assembly_function_test(const int number)
{
	return number * 2;
}

int main(void)
{
	int return_value;
	// const(constant, 상수) ?
	// 엄밀하게 실제로 const는 불변성을 대표함
	// 불변성이란 ?
	// 변하지 않는 성질
	// const 없이도 동작 하는데 붙이는 이유는 ?
	// 1. 메모리 ?
	// 2. 협업 환경에서 변경을 했을 때 문제가 유발될 가능성 원천 차단하기 위해
	const int input_parameter = 3;
	return_value = for_assembly_function_test(input_parameter);
	printf("return_value = %d\n", return_value);
	return 0;
}