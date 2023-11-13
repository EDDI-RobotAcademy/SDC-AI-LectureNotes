#include "vector_store_in_memory_command_handler.h"

void store_vector(vector_model *vector_model_object)
{
    printf("vector 결과 메모리에 저장!\n");

    set_vector_with_domain_model(vector_model_object);
    print_vector();
}