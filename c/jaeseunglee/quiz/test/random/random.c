#include <stdlib.h>
#include <time.h>

#include "random.h"




void random_config()
{
    srand(time(NULL));
}

float generate_random_float(const int min, const int max)
{
    return (float)(rand()%(max*100-min*10+1)+min*10)/100;
}

int generate_random_int(const int min, const int max)
{
    return (int)rand()%(max-min+1)+min;
}

float random_float()
{
    return generate_random_float(RANDOM_MIN, RANDOM_MAX);
}

int random_int()
{
    return generate_random_int(RANDOM_MIN, RANDOM_MAX);
}