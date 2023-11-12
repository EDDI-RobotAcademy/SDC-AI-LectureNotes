#include <stdlib.h>
#include <time.h>
#include "random.h"

#define MAX 9
#define MIN -9

int random_gen()
{
    srand(time(NULL));
    return (rand() % (MAX - MIN + 1)) + MIN;
}