#include "malloc.h"
#include <stdlib.h>

#include <stdio.h>


// 처음 등장하는 포인터
// 포인터는 문법이 상당히 혼란스러움을 많이 가져온다
// 보편적으로 int와 *를 별개로 생각하는 경향이 존재
// 그러나 포인터에서는 'int *' 가 데이터 타입
// int와 int *가 존재한다면 두개는 서로 다른 '데이터 타입'이다
int* integer_dynamic_array;
int current_integer_dynamic_array_index;


void create_int_dynamic_array(int count)
{
	
	// malloc => Memory Allocation의 약자
	// 일반적으로 프로그래밍을 할 때 반드시 알아야 하는 4가지 영역이 존재
	// Stack : 지역 변수
	// Heap : 동적 할당(new malloc)
	// Data : 전역 변수
	// Text : 기계어 영역

	// malloc을 하면 Heap에 Memory를 할당
	// 할당된 메모리의 주소값을 출력(리턴)으로 뱉어냅니다.

	// 포인터 변수의 정의 :
	// 특정한 데이터 타입의 메모리 주소 값을 저장할 수 있는 메모리 공간
	// sizeof(int)는 바이트 수를 가져옵니다 => 4byte

	// 결론적으로 배열의 이름은 배열의 시작주소이고
	// Heap에 할당된 메모리 주소를 받아왔으므로
	// Heap의 영역을 배열처럼 사용할 수 있게 됩니다.
	// 그리고 malloc 앞에 있는 (int *0는
	// int형 포인터로 이 주소를 보겠다는 것을 의미합니다.

	// 4byte * count(5) -> 20byte의 공간을 Heap에 할당 후
	// 이것을 int* (인트형 포인트 변수)로 관리한다
	// == 5개의 int 배열을 만들었다.
	// == arr[5]
	// 이러한 형태로 코드를 작성하면 
	// int arr[count]형태로 배열을 만들 수 있다.
	integer_dynamic_array = (int *)malloc(sizeof(int) * count);
}

bool put_one_integer_data(int data)
{
	
	integer_dynamic_array[current_integer_dynamic_array_index++] = data;
	return true;
}

void print_integer_dynamic_array()
{
	int index;
	printf("malloc을 통해 동적으로 생성한 배열 출력 \n");
	for (index = 0; index < current_integer_dynamic_array_index; index++)
	{
		printf("%3d", integer_dynamic_array[index]);
	}
	printf("\n");
}

void create_char_dynamic_array()
{

}

