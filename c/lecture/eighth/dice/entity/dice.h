#ifndef __DICE_H__
#define __DICE_H__

typedef struct _dice dice;

struct _dice
{
    unsigned int dice_number;
};

#define MIN         1
#define MAX         6

dice *init_dice_object(void);
int get_dice_number(dice *object);
void print_dice_object(dice *object);

#endif