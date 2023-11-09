#include <stdio.h>

#include "player/entity/player.h"

int main (void)
{
    player *player_object;

    printf("Eighth work\n");

    player_object = init_player_object();
    set_player_name(player_object, "낵아마");

    print_player_object(player_object);

    return 0;
}