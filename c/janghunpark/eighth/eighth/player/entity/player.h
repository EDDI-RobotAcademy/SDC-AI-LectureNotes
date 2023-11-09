#ifndef __PLAYER_H__
#define __PLAYER_H__

typedef struct _player player;

struct _player
{
    unsigned int id; // 음수를 쓰지 않겠다는 의지 (0부터 양수인 정수)
    char *name;
};

player *init_player_object(void); // initiate
void set_player_name(player *object, char *name);
void print_player_object(player *object);

#endif