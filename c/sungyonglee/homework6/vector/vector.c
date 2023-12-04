#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "vector.h"

#define MAX_VECTOR          2

unsigned int current_vector_max;

vector *init_vector_object(void)
{
    vector *tmp_vector = (vector *)malloc(sizeof(vector));
    tmp_vector->id = current_vector_max++;
    return tmp_vector;
}

void vector_info_allocation(vector **vector_object_array, char **name)
{
    int i;
    
    for (i = 0; i < MAX_VECTOR; i++)
    {
        vector_object_array[i] = init_vector_object();
        set_vector_name(vector_object_array[i], name[i]);
        print_vector_object(vector_object_array[i]);
    }
}

void set_vector_name(vector *object, char *name)
{
    int name_length = strlen(name) + 1;
    object->name = (char *)malloc(sizeof(char) * name_length);
    strncpy(object->name, name, name_length);
}

void print_vector_object(vector *object)
{
    printf("unique id: %d\n", object->id);
    printf("name: %s\n", object->name);
}