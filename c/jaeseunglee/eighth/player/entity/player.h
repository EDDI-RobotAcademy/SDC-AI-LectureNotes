#ifndef __PLAYER_H__
#define __PLAYER_H__

typedef struct _player player;

struct _player
{
    unsigned int id;
    char *name;
};

player *init_player_object(void);
void set_player_name(player *object, char *name);
void print_player_object(player *object);

#endif