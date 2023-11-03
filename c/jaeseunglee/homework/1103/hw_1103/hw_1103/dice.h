#pragma once
#include "player.h"

extern int player_each_dice_number[MAX_PLAYER_NUMBER];
extern int player1_dice;
extern int player2_dice;

void roll_dice(int index);
void print_dice_number(int index);