#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "malloc_test.h"


// 처음 등장하는 포인터
// 포인터는 문법이 상당히 혼란스러움을 많이 가져오는 녀석입니다.
// 보편적으로 int와 '*' 을 별개로 생각하는 경향이 존재합니다.
// 그러나 포인터에서는 'int *' 이 데이터 타입입니다.
// 'int' 와 'int *' 이 존재한다면 두 개는 서로 다른 '데이터타입' 입니다.

int* integer_dynamic_array;
int current_integer_dynamic_array_index;

void creat_int_dynamic_array(int count)
{
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
	printf("mallloc을 통해 동작으로 생성한 배열 출력 :\n");

	for (index = 0; index < current_integer_dynamic_array_index; index++)
	{
		printf("%3d", integer_dynamic_array[index]);
	}
	printf("\n");
}

void creat_char_dynamic_array()
{
	
}