#include <stdio.h>

// 출력 : int
// 입력 : int number
// 함수 이름 : for_assembly_function_test
int for_assembly_function_test(int number)
{
	return number * 2;
}

int main(void)
{	
	int return_value;
	// const라는 키워드가 새롭게 등장
	// const => constant => 상수
	// const는 불변성을 대표함
	// => const는 변하지 않음
	// const를 붙이는 이유는? 
	// => 협업 환경에서 변경을 했을 때 문제가 유발될 가능성 자체를 원천 차단
	// 일단 const를 붙인 뒤, 전체적으로 봤을 때 변경이 필요한 변수의 
	const int input_parameter = 3;
	return_value = for_assembly_function_test(input_parameter);
	printf("return_value = %d\n", return_value);
	return 0;
}