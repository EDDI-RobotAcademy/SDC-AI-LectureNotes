#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "player.h"

unsigned int current_player_max;

player *init_player_object()
{
    player *temp_player = (player *)malloc(sizeof(player));
    temp_player->id = current_player_max++;
    
    return temp_player;
}

void set_player_name(player *object, char *name)
{
    int name_length = strlen(name)+1;
    object->name = (char*)malloc(name_length);

    strncpy(object->name,name,name_length);
}

void print_player_object(player *object)
{
    printf("unique id: %d\n",object->id);
    printf("name: %s\n",object->name);
}