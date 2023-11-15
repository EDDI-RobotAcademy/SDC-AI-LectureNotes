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
	// 'const' 라는 키워드가 새롭게 등장했음
	// const는 무엇일까 ?
	// constant 약자입니다 (상수)
	// 엄밀하게 실제로 const는 불변성을 대표합니다.
	// 불변성이란 무엇인가?
	// * 변하지 않는 성질
	// const 안 붙여도 동작하는데 번거롭게 이것을 붙이는 이유가 무엇인가 ?
	// 1. 메모리 ?
	// 2. 협업 환경에서 변경을 했을 때 문제가 유발될 가능성 자체를 원천 차단하기 위함
	const int input_parameter = 3;
	return_value = for_assembly_function_test(input_parameter);
	printf("return_value = %d\n", return_value);

	return 0;
}