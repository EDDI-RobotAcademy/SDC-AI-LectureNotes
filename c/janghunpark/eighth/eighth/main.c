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
        // init_player_object()에서 할당된 Heap memory 주소는
        // player_object_array[index]에 배치됨
        
        // 각각의 player_object_array[index]에 가면
        // 결론적으로 player 객체가 있다.
        player_object_array[i] = init_player_object(); 

        // player 객체에 name 설정
        set_player_name(player_object_array[i], name[i]); 

        // player 객체의 정보 출력
        // 여기에 무엇을 전달하는가?
        // 메모리 주소값 <-- 세부사항
        // player 객체 <-- 도메인
        // 결론적으로 아무리 복잡한 상황이더라도 직관성을 제공하는 것이 도메인 관점임
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
            // 주사위를 굴린 것이 아니라 주사위를 생성한 것
            // init_붙은 계열은 C, C++, Java 등의 생성자와 동일하게 여기라고 함
            // malloc을 통해 힙에 메모리를 할당한다는 것을 자연스럽게 생각할 수 있어야 함
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
            
            // 첫 번째 굴린 주사위가 짝수냐를 판정하기 위한 변수
            // 첫 번째 주사위에서 apply_dice_skill을 하지 않도록 디폴트로 false로 설정함
            bool isFirstDiceIsEven = false;

            // 두 번째 주사위를 굴릴 때
            // decision_even과 get_dice_number를 통해 첫 번째 주사위가 짝수인지 여부를 판정하여 
            // isFirstDiceIsEven을 true, false로 만듦
            if (j == SECOND_DICE)
            {
                // ! 는 not 연산자로
                // 참을 부정하면 거짓
                // 거짓을 부정하면 참
                isFirstDiceIsEven = decision_even(get_dice_number(dice_array[i][FIRST_DICE]));

                // 홀수라면 더 이상 진행하지 않음
                if (!isFirstDiceIsEven)
                {
                    // 이 break의 경우 loop 1개를 탈출할 수 있음
                    break;
                }
            }
            // check_first_dice_is_even(j, dice_array);
            // 위와 같은 형태의 method를 구축해 놓았으면 더 좋았을 것

            // 첫 번째 주사위가 짝수임을 판정한 후 두 번째 주사위가 굴러감
            // 첫 번째 주사위 또한 여기서 굴러감
            roll_dice(dice_array[i][j]);
            // 이 지점에서 첫 번째 주사위 숫자 생성
            print_dice_object(dice_array[i][j]);
            // 첫 번째 주사위가 돌아간 직후에는 디폴트로 isFirstDiceIsEven = false 여서 아래는 진행이 안 됨
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

    // dice 포인터를 관리한다는 것은 결론적으로 무엇을 관리하는 것인가?
    // dice 객체를 관리하는 것
    // cf) 이중 포인터: 객체를 관리하는 객체가 있다는 것
    dice *dice_array[MAX_PLAYER][MAX_DICE];

    // 배열의 이름은 배열의 시작 주소고
    // 포인터는 주소를 저장하는 변수라는 것을 상기합시다.
    // player 객체에 name 정보 설정
    // 플레이어 메모리 할당 + 객체 정보 할당
    player_allocation(player_object, name);

    // 주사위 메모리 할당
    dice_memory_allocation(dice_array);
    
    // 할당된 dice 객체 배열을 전달받아
    // 주사위 놀이의 시작
    play_dice_game(dice_array);

    return 0;
}

// [1] + Done : 명령이 실행됐음과 끝남을 의미
// 현재는 도메인 결합이 매우 심한 상태