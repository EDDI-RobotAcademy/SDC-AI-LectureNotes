#include "eleventh.h"

#include <string.h>
#include <stdlib.h>

int index;

eleventh *init_eleven_(eleventh *eleventh_name)
{
    eleventh_name = (eleventh*)malloc(sizeof(eleventh));
    return eleventh_name;
}

void init_char_(char *name)
{
    int name_length = strlen(name) + 1;
    
}