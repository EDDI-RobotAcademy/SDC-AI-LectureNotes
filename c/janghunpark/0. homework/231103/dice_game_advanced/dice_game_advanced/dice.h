#include "player.h"

extern int player_each_dice_number[MAX_PLAYER_NUMBER][MAX_ROLL_NUMBER];

void roll_dice(void);
void print_first_dice_number(void);
void check_even_dice_number(void);
void second_roll_dice(void);
void apply_skill(void);
int find_target_player(int);
void check_winner(void);