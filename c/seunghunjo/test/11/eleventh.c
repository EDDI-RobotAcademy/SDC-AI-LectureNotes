#include "eleventh.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>


eleventh *init_eleven_(void)
{
    eleventh *tmp_eleven = (eleventh*)malloc(sizeof(eleventh));
    return tmp_eleven;
}

void init_char_(eleventh *eleventh_name,char *name)
{
    int name_length = strlen(name) + 1;
    eleventh_name->name = (char*)malloc(sizeof(char)*name_length);
    strncpy(eleventh_name->name,name,name_length);
}

void print_eleveth_name(eleventh *eleventh_name)
{
    printf("이름을 출력합니다: %s\n",eleventh_name->name);
}