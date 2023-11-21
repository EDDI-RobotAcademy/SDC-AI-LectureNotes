#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "vector.h"
#include "../../utility/random/random.h"

vector generate_random_vector(void)
{
    vector random_vector;
    random_vector.x = generate_random_from_min_to_max(MIN, MAX);
    random_vector.y = generate_random_from_min_to_max(MIN, MAX);
    random_vector.z = generate_random_from_min_to_max(MIN, MAX);
    return random_vector;
}

vector relative_vector_generation(vector A, vector B)
{
    vector result;
    result.x = A.x - B.x;
    result.y = A.y - B.y;
    result.z = A.z - B.z;
    return result;
}

void print_each_vector(vector A, vector B)
{
    printf("vector A = { %d, %d, %d }\n", A.x, A.y, A.z);
    printf("vector B = { %d, %d, %d }\n", B.x, B.y, B.z);
}

void print_relative_vector_and_its_length(vector A)
{
    printf("relative_vector = { %d, %d, %d }\n", A.x, A.y, A.z);
    printf("relative vector length = %f\n", sqrt((A.x)*(A.x) + (A.y)*(A.y) + (A.z)*(A.z)));
}