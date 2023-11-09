#include "dice.h"
#include "../../utility/random.h"

#include <stdlib.h>
#include <stdio.h>

dice *init_dice_object()
{
    dice *temp_dice = (dice *)malloc(sizeof(dice));
    temp_dice->dice_number = 
        generate_random_from_min_to_max(DICE_MIN,DICE_MAX);

    return temp_dice;
}

void print_dice_object(dice *object)
{
    printf("데굴데굴: %d\n",object->dice_number);
}