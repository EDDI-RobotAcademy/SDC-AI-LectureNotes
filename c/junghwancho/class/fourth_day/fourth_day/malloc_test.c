#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "malloc_test.h"

#define INT_DYNAMIC_ARRAY_MAX		5


//처음 등장하는 포인터
//포인터는 문법이 상당히 혼란스러움을 많이 가져오는 녀석
//보편적으로 'int'와 '*' 을 별개로 생각하는 경향
//그러나 포인터에서 'int *' 이 데이터 타입.
//'int' 와 'int *'이 존재한다면 두 개는 서로 다른 '데이터타입'
int* integer_dynamic_array;
int current_integer_dynamic_array_index;

char* char_dynamic_array;
int current_char_dynamic_array_index;

void test_local_variable(void)
{
	int test_variable = 3;
}

void create_int_dynamic_array(int count)
{
	//malloc => Mmory Allocation
	// 일반적으로 프로그램을 할 때 반드시 알아야 하는 4가지
	// stack : 지역 변수
	// heap : 동적 할당 (new, malloc)
	// data : 전역 변수
	// test : 기계어 영역

	// malloc을 하면 heap 에 memory 할당 < 함수가 끝나더라도 재사용 가능하다는 뜻
	// 할당된 메모리의 주소값을 출력(리턴값)으로 뱉어냄

	// 포인터 변수의 정의
	// 특정한 데이터 타입의 메모리 주소 값을 저장할 수 있는 메모리 공간
	// sizeof(int)는 바이트 수를 가져옴 => 4
	// 결론적으로 배열의 이름은 배열의 시작 주소이며
	// heap에 할당된 메모리 주소를 받아왔으므로
	// heap의 영역을 배열처럼 사용 할 수 있게 됨
	// 그리고 malloc 앞에 있는 (int *)은 int 형 포인터로 이 주소를 보겠다는 것을 의미

	// 또한 malloc(sizeof(int) * count)는 malloc(4 * 5)로 malloc(20)을 의미함
	// 고로 20byte의 공간을 heap에 할당하였고
	// int *로 바라보므로 int 5개짜리 배열과 동일
	// int arr[5]와 같다는 뜻
	// 즉 이러한 형태의 코드를 작서하면 int arr[count] 형태로 배열을 만들 수 있음
	integer_dynamic_array = (int*)malloc(sizeof(int) * count); // 핵심
}
// bool 은 참/거짓 판정
bool put_one_integer_data(int data)
{
	integer_dynamic_array[current_integer_dynamic_array_index++] = data;
	return true;
}

void print_integer_dynamic_array(void)
{
	int index;
	printf("\n malloc을 통해 동적으로 생성한 배열 출력: \n");

	for (index = 0; index < current_integer_dynamic_array_index; index++)
	{
		printf("%3d", integer_dynamic_array[index]);
	}
	printf("\n");
}

void create_char_dynamic_array(char* name)
{
	//malloc 앞 부분에 (char*) 혹은 (int*) 형태로 붙어 있는 정보가 있는데
	// 이것은 강제 캐스팅이라고 함 : 실제 malloc의 리턴 타입은 void *(void 포인터) 이기 때문에 그럼
	// malloc의 용도가 다양할 수 있음 숫자, 소숫점, 문자열 등 목적이 다양하니까
	// 초기 세팅을 void *(아무 데이터도 없다라는 뜻) 으로 해놓고 사용자가 알아서 맞는 포인터로 캐스팅 해서 써라 
	char_dynamic_array = (char*)malloc(sizeof(char) * (strlen(name) + 1));
}

void set_name_to_char_dynamic_array(char* name)
{
	strncpy(char_dynamic_array, name, strlen(name) + 1);
}

void print_char_dynamic_array(void)
{
	printf("char_dynamic_array = %s\n", char_dynamic_array);
}