#include <stdio.h>
#include "roll_number.h"
#include "random_generator.h"

#define MAX			33
#define MIN			3

int default_number = 0;


void roll_number(void)
{
	roll_number = generate_random(MIN, MAX);
}

void print_random_number(void)
{
	printf("랜덤 숫자 = %d\n", default_number);
}