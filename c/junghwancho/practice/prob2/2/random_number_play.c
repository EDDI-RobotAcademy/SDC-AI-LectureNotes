#include "random_number_play.h"
#include "random_generate.h"

#define MIN         1
#define MAX         10

int get_random_number(void)
{
    return random_generate(MIN, MAX);
}