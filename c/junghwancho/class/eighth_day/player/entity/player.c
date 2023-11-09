#include <string.h>
#include <stdlib.h>
#include <stdio.h> 

#include "player.h"

unsigned int current_player_max; // 양수만 쓰기 위해

player *init_player_object(void)  // id 정의
{
    player *tmp_player = (player *)malloc(sizeof(player));
    // *tmp_player를 player type으로 선언
    // player.h에 정의된 player 메모리 만큼 player *로 사용하겠다.
    //  
    tmp_player->id = current_player_max++;
    
    return tmp_player;
}

void set_player_name(player *object, char *name) // name 정의
{
    int name_length = strlen(name) + 1;

    object->name = (char *)malloc(name_length);
    strncpy(object->name, name, name_length);
}

void print_player_object(player *object) // id, name 출력
{
    printf("unique id: %d\n", object->id);
    printf("name: %s\n", object->name);
}