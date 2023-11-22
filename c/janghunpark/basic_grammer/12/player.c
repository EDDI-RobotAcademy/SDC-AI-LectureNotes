#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "player.h"

unsigned int current_player_max;

#define NUM_OF_PLAYERS      2

player *init_player_object(void)
{
    player *tmp_player = (player *)malloc(sizeof(player));
    tmp_player->id = current_player_max++;
    return tmp_player;
}

void set_player_name(player *object, char *name)
{
    int name_length = strlen(name) + 1;
    object->name = (char *)malloc(sizeof(char) * name_length);
    strncpy(object->name, name, name_length);
}

void print_player_object(player *object)
{
    printf("unique id: %d\n", object->id);
    printf("name: %s\n", object->name);
}

void player_info_allocation(player **object, char **name)
{
    for (int i = 0; i < NUM_OF_PLAYERS; i++)
    {
        object[i] = init_player_object();
        set_player_name(object[i], name[i]);
        print_player_object(object[i]);
    }
}