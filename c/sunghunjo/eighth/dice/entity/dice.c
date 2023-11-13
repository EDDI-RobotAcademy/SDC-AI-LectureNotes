#include "dice.h"
#include "../../utility/random.h"

#include <stdlib.h>
#include <stdio.h>


dice *init_dice_object(void)
{
    dice *tmp_dice = (dice*)malloc(sizeof(dice));
    return tmp_dice;
}

void roll_dice(dice *object)
{
    object->dice_number = 
        generate_random_form_min_to_max(MIN,MAX);
}

int get_dice_number(dice *object)
{
    return object->dice_number;
}

void print_dice_object(dice *object)
{
    printf("주사위 눈금: %d\n", object->dice_number);
}

void add_score(dice *object)
{
    object->dice_number += DICE_TWO_SKILL_NUMBER;
}

void sub_score(dice *targer_object)
{
    targer_object -> dice_number += DICE_THREE_SKILL_NUMBER;
}

void death(dice *object)
{
    object->dice_number = DICE_DEATH_NUMBER;
}