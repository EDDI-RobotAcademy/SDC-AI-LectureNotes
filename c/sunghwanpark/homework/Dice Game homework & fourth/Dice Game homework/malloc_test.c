#include "malloc_test.h"
#include <stdbool.h>
#include <stdlib.h>



//포인터 - 문법이 상당히 혼란스러움을 많이 가져오는 녀석이다. 
// 보편적으로 int와 '*'을 별개로 생각하는 경향이 존재한다. 
// 그러나 포인터에서는 'int *'이 데이터 타입이다. 
// 'int'와 'int *'이 존재한다면 두 개는 서로 다른 '데이터 타입'이다. 
int* integer_dynamic_array;
int current_integer_dynamic_array_index;

void create_int_dynamic_array(int count)
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
	printf("malloc을 통해 동적으로 생성한 배열 출력: \n");

	for (index = 0; index < current_integer_dynamic_array_index; index++)
	{
		printf("%3d", integer_dynamic_array[index]);
	}
	printf("\n");
}
void create_char_dynamic_array()
{
	
}

