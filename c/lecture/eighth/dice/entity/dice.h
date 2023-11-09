#ifndef __DICE_H__
#define __DICE_H__

typedef struct _dice dice;

struct _dice
{
    int dice_number;
};

#define MIN         1
#define MAX         6

#define DICE_TWO_SKILL_NUMBER       3
#define DICE_THREE_SKILL_NUMBER     -4
#define DICE_DEATH_NUMBER           -4444

dice *init_dice_object(void);
void roll_dice(dice *object);
int get_dice_number(dice *object);
void print_dice_object(dice *object);

void add_score(dice *object);
void sub_score(dice *target_object);
void death(dice *object);

#endif