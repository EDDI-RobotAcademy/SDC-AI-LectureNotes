#include <stdio.h>

// 출력: int
// 입력: int number
// 함수 이름: for_assembly_function_test
const int for_assembly_function_test(const int number)
{
	return number * 2;
}

int main(void)
{
	int return_value;
	// const라는 키워드란, constant의 약자로 상수를 의미
	// 엄밀하게 실제로 const는 불변성을 대표 = 변하지 않는 성질
	// const를 안 붙여도 동작하는데 번거롭게 붙이는 이유?
	// 협업 환경에서 변경 했을 때 문제가 유발될 가능성 자체를 원천 차단할 수 있기 때문
	// const를 붙이면 연산을 하려 할 시 compile 자체가 안 됨
	const int input_parameter = 3;
	return_value = for_assembly_function_test(input_parameter);
	printf("return_value = %d\n", return_value);

	return 0;
}