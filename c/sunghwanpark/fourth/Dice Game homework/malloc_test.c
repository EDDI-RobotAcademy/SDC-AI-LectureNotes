#define _CRT_SECURE_NO_WARNINGS
#include "malloc_test.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>



//포인터 - 문법이 상당히 혼란스러움을 많이 가져오는 녀석이다. 
// 보편적으로 int와 '*'을 별개로 생각하는 경향이 존재한다. 
// 그러나 포인터에서는 'int *'이 데이터 타입이다. 
// 'int'와 'int *'이 존재한다면 두 개는 서로 다른 '데이터 타입'이다. 
int* integer_dynamic_array;
int current_integer_dynamic_array_index;

char* char_dynamic_array;
int current_char_dynamic_array_index;

void create_int_dynamic_array(int count)
{	
	// malloc -> Memory Allocation의 약어 
	// 일반적으로 프로그래밍을 할 때 반드시 알아야 하는 4가지 영역이 존재한다. 
	// Stack: 지역 변수 
	// Heap: 동적 할당 (new, malloc)
	// Data: 전역 변수
	// Text: 기계어 영역

	// malloc을 하면 Heap에 Memory를 할당하게 된다. 
	// 할당된 메모리의 주소값을 출력(리턴)으로 뱉어낸다. 

	// 포인터 변수의 정의
	// - 특정한 데이터 타입의 주소 값을 저장할 수 있는 메모리 공간 
	// sizeof(int)는 바이트 수를 가져온다 -> 4 
	// 결론적으로 배열의 이름은 배열의 시작 주소이고 Heap에 할당된 메모리 주소를 받아왔으므로 
	// Heap의 영역을 배열처럼 사용할 수 있게 됐다. 
	// 그리고 malloc 앞에 있는 (int *)는 int형 포인터로 이 주소를 보내겠다는 의미다. 

	// 또한 malloc(sizeof(int)*count)는 malloc(4*5)로 malloc(20)을 의미한다. 
	// 고로 20byte의 공간을 Heap에 할당하였고 int *로 바라보므로 int 5개짜리 배열과 동일하다. 
	// int arr[5]와 같다는 뜻이다. 
	// 즉, 이러한 형태로 코드를 작성하면 int arr[count]의 형태로 배열을 만들 수 있다. 
	integer_dynamic_array = (int*)malloc(sizeof(int) * count);
}

bool put_one_integer_data(int data)
{
	integer_dynamic_array[current_integer_dynamic_array_index++] = data;
	return true;
}
void print_integer_dynamic_array(void)
{
	int index;
	printf("malloc을 통해 동적으로 생성한 배열 출력: \n");

	for (index = 0; index < current_integer_dynamic_array_index; index++)
	{
		printf("%3d", integer_dynamic_array[index]);
	}
	printf("\n");
}
void create_char_dynamic_array(char* name)
{
	//malloc 앞 부분에 (char*) 혹은 (int*) 형태호 붙어 있는 정보가 있다. 
	// 이것은 강제 캐스팅인데 실제 malloc의 리턴 타입은 void *이기 때문에 그렇다. 
	char_dynamic_array = (char*)malloc(sizeof(char) * (strlen(name)+1));
}

void set_name_to_char_dynamic_array(char* name)
{
	strncpy(char_dynamic_array, name, strlen(name) + 1);
}

void print_char_dynamic_array(void)
{
	printf("char_dynamic_array: %s\n", char_dynamic_array);
}

