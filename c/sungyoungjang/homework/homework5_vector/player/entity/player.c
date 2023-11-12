#include "player.h"
#include <stdio.h>

char *playerNames[MAX_PLAYER] =
{
    "애비셋",
    "피치브라더스"
};

void printPlayerNames() 
{
    int i;
    for (i = 0; i < MAX_PLAYER; i++) 
    {
        printf("Player %d: %s\n", i + 1, playerNames[i]);
    }
}