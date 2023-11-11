#include <stdlib.h>

#include "vector.h"
#include "../../utility/random.h"

vector *init_vector_object(void)
{
    vector *tmp_vector_number = (vector *)malloc(sizeof(vector));
    return tmp_vector_number;
}

void set_vector_value(vector *number)
{
    number->vector_value = generate_random_from_min_to_max(MIN, MAX);
}

void get_vector_value(vector *number)
{
    return number->vector_value;
}

void print_vector_value(vector *number)
{
    printf("%d", number->vector_value);
}