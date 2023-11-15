#include "player.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

player *set_player_name(player *object, char *name)
{
    int name_length = strlen(name) + 1;
    object->name = (char *)malloc(name_length);
    strncpy(object->name, name, name_length);
    return object;
}

void print_player_object(player *object)
{
    printf("name: %s\n", object->name);
}