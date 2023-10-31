// stdio => Standard IO 의 약자
// printf() 를 사용하려면 #include <stdio.h> 가 필요합니다.
#include <stdio.h>
#include "second.h"

// void의 영어 의미는 '공허한, 텅빈'
// 함수를 작성하는 요령
// 
// 1. 먼저 return (리턴) 타입을 작성합니다.
// [리턴 타입이란 결론적으로 출력을 의미합니다.]
// 2. 함수의 이름을 작성합니다 (자유롭게 작성) <- 어떤 작업인지 의미 전달이 쉽게 이름을 작성합니다.
// [ 약자로 이름을 지으면 혼선이 발생 할 수 있으므로 풀 네이밍으로 작성합니다! ]
// 3. 소괄호를 열고 닫은 이후 파라미터(인자 혹은 입력) 타입을 작성합니다.
void second_function(void) {
	int number = 3;
	printf("숫자 = %d\n", number);
}