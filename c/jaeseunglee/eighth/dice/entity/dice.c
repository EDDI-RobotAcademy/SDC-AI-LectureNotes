#include "dice.h"
#include "../../utility/random.h"

#include <stdlib.h>
#include <stdio.h>

dice *init_dice_object()
{
    dice *temp_dice = (dice *)malloc(sizeof(dice));
    return temp_dice;
}

void roll_dice(dice *object)
{
    object->dice_number = 
        generate_random_from_min_to_max(DICE_MIN,DICE_MAX);

}

int get_dice_number(dice *object)
{
    return object->dice_number;
}

void print_dice_number(dice *object)
{
    printf("데굴데굴: %d\n",object->dice_number);
}

void add_score(dice *object)
{
     printf("버프 발동! %d -> %d\n", object->dice_number,object->dice_number+BUFF_AMOUNT);
    object->dice_number += BUFF_AMOUNT;
}

void attack_score(dice *object)
{
    printf("디버프 발동! %d -> %d\n", object->dice_number,object->dice_number-DEBUFF_AMOUNT);
    object->dice_number -= DEBUFF_AMOUNT;
}

void death(dice *object)
{
    printf("사망!!\n");
    object->dice_number = DEATH;
}