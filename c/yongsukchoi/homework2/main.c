#include <stdio.h>
#include "vector/vector.h"
#include "generator/random_generator.h"

int main (void)
{
    vector* A;
    vector* B;
    vector* result;

    random_config();

    A = init_vector("A");
    B = init_vector("B");
    result = init_vector("결과");

    print_vector_info(A);
    print_vector_info(B);
    
    calc_vector(A, B, result);

    print_vector_info(result);

    free_vector(A);
    free_vector(B);
    free_vector(result);

    return 0;
}
