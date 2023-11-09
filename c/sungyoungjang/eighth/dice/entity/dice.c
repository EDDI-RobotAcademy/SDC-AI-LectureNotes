#include "dice.h"
#include "../../utility/random.h"

#include <stdio.h>

dice *init_dice_object(void)
{
    dice *tmp_dice = (dice *)malloc(sizeof(dice));
    tmp_dice->dice_number = 
        generate_random_from_min_to_max(MIN,MAX);
    
    return tmp_dice;
}

int get_dice_number(dice *object)
{
    return object->dice_number;
}

void print_dice_object(dice *object)
{
    printf("주사위 눈금: %d\n", object->dice_number);
}