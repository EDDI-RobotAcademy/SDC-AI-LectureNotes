#ifndef __DICE_H__
#define __DICE_H__

typedef struct _dice dice;

struct _dice
{
    unsigned int dice_number;
};

dice *init_dice_object();
void print_dice_number(dice *object);
#define DICE_MIN         1
#define DICE_MAX         6

#endif