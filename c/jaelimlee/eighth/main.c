#include <stdio.h>

#include "player/entity/player.h"
#include "dice/entity/dice.h"
#include "utility/random.h"

#define MAX_PLAYER      2

int main (void)
{
    int i;
    player *player_object[MAX_PLAYER];
    char *name[MAX_PLAYER] = {
        "낵아마",
        "낵아뭐"
    };

    dice *dice_array[MAX_PLAYER];

    printf("Eighth work\n");

    for (i =0; i <MAX_PLAYER; i++)
    {
        player_object[i] = init_player_object();
        set_player_name(player_object[i], name[i]);
        print_player_object(player_object[i]);
    }

    random_seed_config();

    for (i = 0; i < MAX_PLAYER; i++)
    {
        dice_array[i] = init_dice_object();
        print_dice_object(dice_array[i]);
    }

    return 0;
}