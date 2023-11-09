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
    tmp_player->id = current_player_max++;
    // current_player_max 값을 tmp_player의 id 값에 대입하고 ++
    return tmp_player;
    // malloc에 의해 생성된 heap 메모리 주소에 id의 current_player_max 값 설정 후 리턴
}

void set_player_name(player *object, char *name)
// *object를 player type으로 선언하고, *name의 문자열을 받아 set_player_name 수행
{
    int name_length = strlen(name) + 1;
    // strln

    object->name = (char *)malloc(name_length);
    strncpy(object->name, name, name_length);
}

void print_player_object(player *object) // id, name 출력
{
    printf("unique id: %d\n", object->id);
    printf("name: %s\n", object->name);
}