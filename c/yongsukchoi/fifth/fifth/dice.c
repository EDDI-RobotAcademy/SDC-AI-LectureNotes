#include "dice.h"
#include "random.h"

#define MIN			1
#define MAX			6

int roll_dice() {
	return get_random_from_min_to_max(MIN, MAX);
}