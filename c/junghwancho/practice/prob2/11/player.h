#ifndef __PLAYER_H__
#define __PLAYER_H__

typedef struct _player player;

struct _player
{
    char *name;
};

player *set_player_name(player *object, char *name);
void print_player_object(player *object);
#endif