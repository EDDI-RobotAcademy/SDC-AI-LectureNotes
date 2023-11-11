#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "player.h"

unsigned int current_player_max;

// Stack: 지역 변수 --> 함수가 끝나면 유지가 안 됨 (기계어를 부석한 이유)
// Heap: 동적 할당 (malloc, new) --> 함수가 끝나도 유지가 됨
// Data: 전역 변수
// Text: 기계어

player *init_player_object(void)
{
    // Heap에 할당한 메모리가 어디에 들어가는가?
    // 정답 = tmp_player(heap에 주소가 들어있는 것)
    // 여기서 생성된 것은 player 만큼 메모리를 할당하였음 <-- 기능 관점
    // player 객체 생성 <-- 도메인 관점
    player *tmp_player = (player *)malloc(sizeof(player));
    // 사용자의 고유값을 지정하기 위해 id value가 필요한 것임
    // 코드를 작성하며 지속적 관리 필요성을 생각해야 함
    tmp_player->id = current_player_max++;

    // tmp_player를 return 하면 할당된 Heap 메모리 주소가 리턴됨
    return tmp_player;
}

// 이미 init에서 객체를 생성했으므로 object를 가지고 지지고 볶음
void set_player_name(player *object, char *name)
{
    int name_length = strlen(name) + 1;

    // char 이름을 할당해서 object->name 에 저장하기 위해서 <-- 기능 관점(코드를 작성할 때)
    // 포인터는 반드시 메모리를 할당하고 사용해야 한다. <-- 기능 관점의 추가 확장
    // object->name 에 문자열 객체를 생성하기 위해서 <-- 도메인 관점(코드를 해석할 때)
    object->name = (char *)malloc(sizeof(char) * name_length);
    strncpy(object->name, name, name_length);
}

void print_player_object(player *object)
{
    printf("unique id: %d\n", object->id);
    printf("name: %s\n", object->name);
}