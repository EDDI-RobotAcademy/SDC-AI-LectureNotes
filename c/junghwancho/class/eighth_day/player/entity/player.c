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
// 여기서 object라는 포인터로 player * 객체의 주소를 저장하고 아래에서 object를 이용해 player 객체 주소에 접근하도록 한다.
{
    int name_length = strlen(name) + 1;
    // name으로 받은 문자열에 + 1 을 해서 name_length에 대입

    object->name = (char *)malloc(name_length);
    // name_length 만큼의 메모리를 사용하는 char * 파라메타를 생성하고 이거를 name에 대입(저장)
    // object는 구조체 안의 정보를 가져오는데, 가독성을 위해 임의 생성한 단어로 의미는 크게 없고 구조만 알자
    strncpy(object->name, name, name_length);
    // char *name, name_length를 받아 player 구조체의 name에 저장 
}

void print_player_object(player *object) // id, name 출력
{
    printf("unique id: %d\n", object->id);
    printf("name: %s\n", object->name);
}