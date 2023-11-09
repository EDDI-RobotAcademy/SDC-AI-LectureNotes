#include <stdio.h>

#include "dice/entity/dice.h"
#include "player/entity/player.h"
#include "utility/random.h"

#define MAX_PLAYER      2

int main(void)
{
    int loop;
    player *player_object[MAX_PLAYER];
    char *name[MAX_PLAYER] ={
        "오케이",
        "ㅁㄴㅇㄹ"
    };

    dice *dice_arr[MAX_PLAYER];


    printf("Eighth work!!!\n");

    for(loop = 0;loop<MAX_PLAYER;loop++)
    {
        player_object[loop] = init_player_object();
        set_player_name(player_object[loop],name[loop]);

        print_player_object(player_object[loop]);
    }
    
    random_config();
    for(loop = 0; loop<MAX_PLAYER;loop++)
    {
        dice_arr[loop] = init_dice_object();
        print_dice_object(dice_arr[loop]);
    }


    return 0;
}







