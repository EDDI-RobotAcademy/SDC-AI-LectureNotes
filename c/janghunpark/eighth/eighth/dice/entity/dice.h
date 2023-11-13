#ifndef __DICE_H__
#define __DICE_H__

#define MIN     1
#define MAX     6

#define DICE_TWO_SKILL_NUMBER           3
#define DICE_THREE_SKILL_NUMBER         -4
#define DICE_DEATH_NUMBER               -4444

typedef struct _dice dice;

// 구조체는 기본적으로 여러 타입을 포함한 배열
struct _dice
{
    int dice_number; // -4444를 하면 음수가 될 수도 있기 때문에 여기서는 int
};

dice *init_dice_object(void);
void print_dice_object(dice *object);
int get_dice_number(dice *object);
void roll_dice(dice *object);
void add_score(dice *object);
void sub_score(dice *target_object);
void death(dice *object);

#endif