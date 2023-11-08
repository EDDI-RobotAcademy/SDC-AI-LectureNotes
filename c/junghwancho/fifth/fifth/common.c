#include "common.h"

bool check_even(int first_dice_number)
{
	// C에서 0은 false, 0이 아니면 true
	return (first_dice_number % 2) ? false : true;
}
