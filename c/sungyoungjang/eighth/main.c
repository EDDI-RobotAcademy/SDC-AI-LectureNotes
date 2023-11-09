#include <stdio.h>

#include "player/entity/player.h"
#include "dice/entity/dice.h"
#include "utility/random.h"
#include "utility/common.h"

#define MAX_PLAYER      2
#define MAX_DICE        2

#define FIRST_DICE       0
#define SECOND_DICE      1

int main(void)
{
    int i,j;

    player *player_object[MAX_PLAYER];
    char *name[MAX_PLAYER] = {
        "알파",
        "베타"
    };

    dice *dice_array[MAX_PLAYER][MAX_DICE];

    printf("Eighth work\n");

    for(i = 0; i < MAX_PLAYER; i++)
    {   
        player_object[i] = init_player_object();
        set_player_name(player_object[i], name[i]);

        print_player_object(player_object[i]);
    }

    random_seed_config();

    for(i = 0; i < MAX_PLAYER; i++)
    {
        printf("player: %d\n", i);
        for (j = 0; j < MAX_DICE; j++)
        {
            
            if (j == SECOND_DICE)
            {

                
                // '!'는 not 연산자로
                // 참을 부정하면 거짓
                // 거짓을 부정하면 참
                if(!decsion_even(
                    get_dice_number(dice_array[i][FIRST_DICE])))
                {
                    break;
                }
            }
            dice_array[i][j] = init_dice_object();
            print_dice_object(dice_array[i][j]);
        }
    }
    
    return 0;
}