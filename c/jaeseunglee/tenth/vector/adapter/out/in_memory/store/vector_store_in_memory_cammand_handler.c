#include "vector_store_in_memory_cammand_handler.h"
#include "../data/vector.h"

#include <stdio.h>

void store_vector(vector_model *vector_object)
{
    printf("vector 결과 메모리에 저장!\n");

    set_vector_with_domain_model(vector_object);
    print_vector();
}
