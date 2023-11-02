#include <stdio.h>

// 출력 : int
// 입력 : int number
// 함수 이름 : for_assembly_function_test
int for_assembly_function_test(int number)
{
	return number * 3;
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
	// 일단 const를 붙인 뒤, 전체적으로 봤을 때 변경이 필요한 변수의 const를 제거 
	const int input_parameter = 211;

	/*int a = 123123;
	const int b = 22;
	int c = 33;
	int c1 = 33;
	int c2 = 33;
	int c3 = 33;
	int c4 = 33;
	int c5 = 33;
	int c6 = 33;
	int c7 = 33;
	int c8 = 33; 
	int c9 = 33;
	int c0 = 33;
	int c11 = 33;
	int c12 = 33;
	int c13 = 33;
	int c14 = 33;
	int c15 = 33;
	int c16 = 33;
	int c17 = 33;*/

	
	return_value = for_assembly_function_test(input_parameter);
	printf("return_value = %d\n", return_value);
	return 0;
}