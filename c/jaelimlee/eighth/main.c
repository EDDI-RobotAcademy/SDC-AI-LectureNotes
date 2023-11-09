#include <stdio.h>

#include "player/entity/player.h"
#include "dice/entity/dice.h"
#include "utility/random.h"
#include "utility/common.h"

#define MAX_PLAYER          2
#define MAX_DICE            2

#define FIRST_DICE          0
#define SECOND_DICE         1

int find_target_dice(int current_index)
{
    return current_index ? 0 : 1;
}

int main (void)
{
    int i, j;
    player *player_object[MAX_PLAYER];
    char *name[MAX_PLAYER] = {
        "낵아마",
        "낵아뭐"
    };

    dice *dice_array[MAX_PLAYER][MAX_DICE];

    printf("Eighth work\n");

    for (i = 0; i < MAX_PLAYER; i++)
    {
        player_object[i] = init_player_object();
        set_player_name(player_object[i], name[i]);
        print_player_object(player_object[i]);
    }

    random_seed_config();

    for (i = 0; i < MAX_PLAYER; i++)
    {
        for (j = 0; j < MAX_DICE; j++)
        {
            dice_array[i][j] = init_dice_object();
        }
    }

    for (i = 0; i < MAX_PLAYER; i++)
    {
        printf("player: %d\n", i);
        for (j = 0; j < MAX_DICE; j++)
        {
            bool isFirstDiceIsEven = false;
            if (j == SECOND_DICE)
            {
                // '!' 는 NOT 연산자로
                // 참을 부정하면 거짓
                // 거짓을 부정하면 참
                isFirstDiceIsEven = decision_even(
                        get_dice_number(dice_array[i][FIRST_DICE]));

                if (!isFirstDiceIsEven)
                {
                    break;
                }
            }
            
            roll_dice(dice_array[i][j]);
            print_dice_object(dice_array[i][j]);

            if (isFirstDiceIsEven)
            {
                int target_index;
                int second_dice = get_dice_number(
                    dice_array[i][SECOND_DICE]);

                switch (second_dice)
                {
                    case 2:
                        printf("2번 스킬: +3\n");
                        add_score(dice_array[i][SECOND_DICE]);
                        break;

                    case 3:
                        printf("3번 스킬: -4\n");
                        target_index = find_target_dice(i);
                        sub_score(dice_array[target_index][SECOND_DICE]);
                        break;

                    case 4:
                        printf("뒤졌음: -4444\n");
                        death(dice_array[i][SECOND_DICE]);
                        break;

                    default:
                        break;
                }
            }
        }
    }

    return 0;
}