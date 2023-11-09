#include <stdio.h>
#include <stdbool.h>

#include "dice/entity/dice.h"
#include "player/entity/player.h"
#include "utility/random.h"
#include "utility/common.h"

#define MAX_PLAYER      2
#define MAX_DICE        2
#define FIRST_DICE      0
#define SECOND_DICE      1

int find_target_dice(int current_index)
{
    return current_index ? 0 : 1;
}

int main(void)
{
    
    int current_player_index;
    int current_dice_index;
    player *player_object[MAX_PLAYER];
    char *name[MAX_PLAYER] ={
        "오케이",
        "ㅁㄴㅇㄹ"
    };

    dice *dice_arr[MAX_PLAYER][MAX_DICE];

    for(current_player_index=0;current_player_index<MAX_PLAYER;current_player_index++)
    {
        for(current_dice_index=0;current_dice_index<MAX_DICE;current_dice_index++)
        {
            dice_arr[current_player_index][current_dice_index] = init_dice_object();
        }
    }


    printf("Eighth work!!!\n");
    
        random_config();

    for(current_player_index = 0;current_player_index<MAX_PLAYER;current_player_index++)
    {
        player_object[current_player_index] = init_player_object();
        set_player_name(player_object[current_player_index],name[current_player_index]);

        print_player_object(player_object[current_player_index]);
        
         for(current_dice_index = 0 ; current_dice_index < MAX_DICE; current_dice_index++)
        {
            roll_dice(dice_arr[current_player_index][current_dice_index]);
            

            if(current_dice_index == SECOND_DICE)
            {
                if(!check_even(get_dice_number(dice_arr[current_player_index][FIRST_DICE])))
                {
                    break;
                }
                else
                {
                        print_dice_number(dice_arr[current_player_index][current_dice_index]);
                        switch (dice_arr[current_player_index][SECOND_DICE]->dice_number){
                        case 2:
                          
                            add_score(dice_arr[current_player_index][SECOND_DICE]);

                            break;
                        case 3:
                          
                            
                            int target = find_target_dice(current_player_index);
                          
                            attack_score(dice_arr[target][SECOND_DICE]);
                          
                            break;
                        case 4:
                            death(dice_arr[current_player_index][SECOND_DICE]);
                            break;
                        default:
                            printf("스킬 사용 실패!\n");
                            break;
                    }
               
                }
            }
            else
            {
                print_dice_number(dice_arr[current_player_index][current_dice_index]);
            }
            
            
            
            
        }

       
    }
    
    
   

    return 0;
}







