#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "player.h"

unsigned int current_player_max;

// 가장 기본적인 Virtual Memory Layout 은 아래와 같습니다.
// Stack: 지역 변수 <- 기계어를 분석한 이유
// Heap: 동적 할당 (malloc, new)
// Data: 전역 변수
// Text: 기계어

player *init_player_object(void)
{
    // Heap의 할당한 메모리 주소가 어디에 들어가는가 ? tmp_player
    // 여기서 생성된 것은 무엇인가 ?
    // player 크기 만큼 메모리를 할당하였음 <--- 기능 관점
    // player 객체 생성 <- 도메인 관점
    player *tmp_player = (player *)malloc(sizeof(player));
    tmp_player->id = current_player_max++;

    // 그렇다면 tmp_player를 return 하면 무엇이 return 되는가 ?
    // 할당된 Heap 메모리 주소가 return 됨
    return tmp_player;
}

// 이미 init에서 객체를 생성했으므로 object를 가지고 지지고 볶음
void set_player_name(player *object, char *name)
{
    int name_length = strlen(name) + 1;

    // char 이름을 할당해서 object->name에 저장하기 위해서 ???? <--- 기능 관점
    // 포인터는 반드시 메모리를 할당하고 사용해야 한다 <<--- 기능 관점의 추가적 확장
    // 너무 세부사항 관점으로 문제를 바라보고 있음
    
    // object->name에 문자열 객체를 생성하기 위해서 <--- 도메인 관점
    // 그래서 Java에도 String 클래스(구조체) 타입이 있는 것임
    object->name = (char *)malloc(sizeof(char) * name_length);
    strncpy(object->name, name, name_length);
}

void print_player_object(player *object)
{
    printf("unique id: %d\n", object->id);
    printf("name: %s\n", object->name);
}
