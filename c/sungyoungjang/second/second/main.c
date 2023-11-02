#include <stdio.h>

// 출력 : int
// 입력 : int number
// 함수이름 : for_assembly_function_test
//


const int for_assembly_function_test(const int number)
{
	return number * 2;
}

int main(void)
{
	int return_value;
	const int input_parameter = 3;

	// 'const' 라는 키워드가 새롭게 등장
	// const 는 무엇인가?
	// constant의 약자 = 상수
	// 엄밀하게 실제로 const는 불변성을 대표.
	//불변성이란? - 변하지 않는 성질
	// const를 안붙여도 동작하는데 번거롭게 붙이는 이유.
	// **<협업 환경에서 변경을 했을 떄 문제가 유발될 가능성을 자체를 원천 차단하기 위함>**
	//
	return_value = for_assembly_function_test(input_parameter);
	printf("return = %d\n", return_value);
	return 0;
}