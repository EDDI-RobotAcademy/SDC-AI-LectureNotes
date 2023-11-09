#ifndef __DICE_H__
#define __DICE_H__

typedef struct _dice dice;

struct _dice
{
    int dice_number;
};

dice *init_dice_object();
void print_dice_number(dice *object);
int get_dice_number(dice *object);
void roll_dice(dice *object);

void add_score(dice *object);
void attack_score(dice *object);
void death(dice *object);

#define DICE_MIN            1
#define DICE_MAX            6

#define BUFF_NUMBER         2
#define DEBUFF_NUMBER       3
#define DEATH_NUMBER        4

#define BUFF_AMOUNT         3  
#define DEBUFF_AMOUNT       4
#define DEATH             -4444

#endif