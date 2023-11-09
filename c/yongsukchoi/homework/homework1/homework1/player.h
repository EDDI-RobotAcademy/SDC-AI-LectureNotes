#pragma once

#define PLAYER_COUNT			2
#define PLAYER_NAME_LENGTH		32

extern char player[PLAYER_COUNT][PLAYER_NAME_LENGTH];

void set_player_name(char name[]);
void print_player_name(void);