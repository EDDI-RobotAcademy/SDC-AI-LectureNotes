#include <stdio.h>

#include "player/entity/player.h"
#include "dice/entity/dice.h"
#include "utility/random.h"
#include "utility/common.h"

#define MAX_PLAYER      2
#define MAX_DICE        2

#define FIRST_DICE      0
#define SECOND_DICE     1

// 변경사항이 있을 경우 재빌드 command
// rm -rf *
// cmake ..

int find_target_dice(int current_index)
{
    return current_index ? 0 : 1;
}

// 배열의 이름은 배열의 시작 주소
// 포인터는 주소값을 저장할 수 있는 
// player *player_object[MAX_PLAYER]; 배열(주소값의 다발)의 이름을 전달
// *하나랑 [MAX_PLAYER]를 교체할 수 있음
// 기계어에 대한 이해는 반드시 해야 한다.
void player_allocation(player **player_object_array, char **name)
{
    int i;

    for (i = 0; i < MAX_PLAYER; i++)
    {
        player_object_array[i] = init_player_object(); // 이름의 길이를 고려하여 메모리 할당
        set_player_name(player_object_array[i], name[i]); // 
        print_player_object(player_object_array[i]);
    }
}

// 모든 경우의 수에 메모리 할당
void dice_memory_allocation(dice *dice_array[MAX_PLAYER][MAX_DICE])
{
    int i, j;

    random_seed_config();

    for (i = 0; i < MAX_PLAYER; i++)
    {
        for (j = 0; j < MAX_DICE; j++)
        {
            dice_array[i][j] = init_dice_object();
        }
    }
}

void apply_dice_skill(bool isFirstDiceIsEven, dice *dice_array[MAX_PLAYER][MAX_DICE], int player_index)
{
    if (isFirstDiceIsEven)
    {
        int target_index;
        int second_dice = get_dice_number(dice_array[player_index][SECOND_DICE]);                
        
        switch (second_dice)
        {
            case 2:
                printf("2번 스킬: +3\n");
                add_score(dice_array[player_index][SECOND_DICE]);
                break;

            case 3:
                printf("3번 스킬: 상대방 -4\n");
                target_index = find_target_dice(player_index);
                sub_score(dice_array[target_index][SECOND_DICE]);
                break;

            case 4:
                printf("바로 죽음: -4444\n");
                death(dice_array[player_index][SECOND_DICE]);
                break;
            
            default:
                break;
        }
    }
}

void play_dice_game(dice *dice_array[MAX_PLAYER][MAX_DICE])
{
    int i, j;
    
    for (i = 0; i < MAX_PLAYER; i++)
    {
        printf("player: %d\n", i);
        // 플레이어가 각각 주사위 2개씩 굴리기
        for (j = 0; j < MAX_DICE; j++)
        {
            // '!' 는 NOT 연산자로 참을 부정하면 거짓, 거짓을 부정하면 참

            bool isFirstDiceIsEven = false;

            if (j == SECOND_DICE)
            {
                isFirstDiceIsEven = decision_even(get_dice_number(dice_array[i][FIRST_DICE]));

                if (!isFirstDiceIsEven)
                {
                    break;
                }
            }

            roll_dice(dice_array[i][j]);
            print_dice_object(dice_array[i][j]);

            apply_dice_skill(isFirstDiceIsEven, dice_array, i);
            
        }
    }
}

int main (void)
{
    printf("Eighth Work\n");

    // 객체 관점에서 플레이어 객체를 관리하는 배열
    // Player playerArray[MAX_PLAYER]; <- Java
    // player는 커스텀한 데이터타입
    // int vs int *의 차이점은 무엇인가?
    // int는 메모리 안에 값이 들어 있는 것이고, int *는 메모리 안에 메모리가 들어 있음
    // int number = 4;
    // int *pointer = &number;

    // number의 메모리      4
    //   pointer        number
    player *player_object[MAX_PLAYER];
    char *name[MAX_PLAYER] = {
        "안녕" ,
        "잘가"
    };

    dice *dice_array[MAX_PLAYER][MAX_DICE];

    // player allocation
    player_allocation(player_object, name);

    // dice memory allocation
    dice_memory_allocation(dice_array);
    
    play_dice_game(dice_array);

    return 0;
}

// [1] + Done : 명령이 실행됐음과 끝남을 의미
// 현재는 도메인 결합이 매우 심한 상태