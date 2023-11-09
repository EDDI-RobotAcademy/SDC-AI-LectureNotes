#include <stdio.h>

#include "player/entity/player.h"

#define MAX_PLAYER              2

int main(void)
{
    int i;
    player *player_object[MAX_PLAYER];
    char *name[MAX_PLAYER] = {
        "갱플랭크",
        "레넥톤"
    };

    printf("Eighth work\n");

    for(i = 0; i < MAX_PLAYER; i++)
    {
        player_object[i] = init_player_object();
        set_player_name(player_object[i],name[i]);
        print_player_object(player_object[i]);
    }

    return 0;
}