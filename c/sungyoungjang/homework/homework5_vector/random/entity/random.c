#include "random.h"
#include <stdlib.h>

#define MAX 9
#define MIN -9

int random_gen() {
    return (rand() % (MAX - MIN + 1)) + MIN;
}