#include <stdlib.h>
#include <time.h>

#include "random.h"




void random_config()
{
    srand(time(NULL));
}

float generate_random_float(const int from, const int to)
{
    int min = from *100;
    int max = to * 100;

    return (float)(rand()%(max-min+1)+min)/100;
}

int generate_random_int(const int min, const int max)
{
    return (int)rand()%(max-min+1)+min;
}

float random_float()
{
    //return generate_random_float(RANDOM_MIN, RANDOM_MAX);

    return generate_float_random_advanced(RANDOM_MIN,RANDOM_MAX,SIGNIFICANT);
}

int random_int()
{
    return generate_random_int(RANDOM_MIN, RANDOM_MAX);
}

int process_for_expression_float(const int int_number, const int significant)
{
    return int_number * pow(BASE_TEN, significant);
}

float generate_float_random_advanced(
    const int min, const int max, const int significant)
{
    // 100 ~ 10100
    int tmp_random = rand() % 
        (process_for_expression_float(max, significant) - 
        process_for_expression_float(min, significant) + 1) + 
        process_for_expression_float(min, significant);

    return tmp_random / pow(BASE_TEN, significant);
}