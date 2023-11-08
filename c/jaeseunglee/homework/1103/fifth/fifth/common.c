#include "common.h"

bool check_even(const int number)
{
	// C에서 0은 false, 0이 아니면 true;
	return number % 2 ? false : true;
}
