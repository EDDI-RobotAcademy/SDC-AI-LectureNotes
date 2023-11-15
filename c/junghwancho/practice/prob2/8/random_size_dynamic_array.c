

void random_size_dynamic_array(int random_size)
{   
    int *dynamic_array;
    dynamic_array = (int*)malloc(sizeof(int) *random_size);

    for (int i = 0; i < random_size; i++){
      
        dynamic_array = get_random_number();
        printf("random_number_dynamic_array %d\n", dynamic_array);
    }
}