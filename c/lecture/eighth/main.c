#include <stdio.h>

#include "player/entity/player.h"
#include "dice/entity/dice.h"
#include "utility/random.h"
#include "utility/common.h"

#define MAX_PLAYER          2
#define MAX_DICE            2

#define FIRST_DICE          0
#define SECOND_DICE         1

void play_dice_game(dice *dice_array[MAX_PLAYER][MAX_DICE]);

int find_target_dice(int current_index)
{
    return current_index ? 0 : 1;
}

//                          player *player_object[MAX_PLAYER];
void player_info_allocation(player **player_object_array, char **name)
{
    int i;

    for (i = 0; i < MAX_PLAYER; i++)
    {
        // init_player_object()에서 할당된 Heap Memory 주소는
        // player_object_array[index]에 배치됨

        // 각각의 player_object_array[index]에 가면 무엇이 있는가 ?
        // Heap에 저장된 메모리 주소 ???? 
        // 결론적으로 player 객체
        player_object_array[i] = init_player_object();

        // player 객체에 name 값 설정
        set_player_name(player_object_array[i], name[i]);

        // player 객체의 toString() 매서드 <- Java 스타일 표현
        // player 객체의 정보 출력 <- Java 따윈 모를 경우
        // 여기에 무엇을 전달하는가 ?

        // 메모리 주소값 <--- 세부 사항
        // player 객체 <--- 도메인
        // 결론적으로 아무리 복잡한 상황이더라도 직관성을 제공하는 것이 Domain(도메인) 관점임
        print_player_object(player_object_array[i]);
    }
}

void dice_memory_allocation(dice *dice_array[MAX_PLAYER][MAX_DICE])
{
    int i, j;

    random_seed_config();

    for (i = 0; i < MAX_PLAYER; i++)
    {
        for (j = 0; j < MAX_DICE; j++)
        {
            // 여기서 주사위 객체를 만들어서 배열이 관리하게 만듬
            // 그래서 init_ 붙은 계열을 전부 C++, Java 등의 생성자와 동일하게 여기라고 했음.
            // 결론적으로 내부에서 malloc()을 사용 할 것임을 알 수 있음.
            dice_array[i][j] = init_dice_object();
        }
    }
}

void apply_dice_skill(bool isFirstDiceIsEven, 
                    dice *dice_array[MAX_PLAYER][MAX_DICE], 
                    int player_index)
{
    if (isFirstDiceIsEven)
    {
        int target_index;
        int second_dice = get_dice_number(
            dice_array[player_index][SECOND_DICE]);

        switch (second_dice)
        {
            case 2:
                printf("2번 스킬: +3\n");
                add_score(dice_array[player_index][SECOND_DICE]);
                break;
            
            case 3:
                printf("3번 스킬: -4\n");
                target_index = find_target_dice(player_index);
                sub_score(dice_array[target_index][SECOND_DICE]);
                break;
            
            case 4:
                printf("뒤졌음: -4444\n");
                death(dice_array[player_index][SECOND_DICE]);
                break;
            
            default:
                break;
        }
    }
}



int main (void)
{
    // int i, j;
    // player 객체를 관리하는 배열
    // Player playerArray[MAX_PLAYER]; <- Java
    // player는 무엇인가 ?
    // 우리가 커스텀한 데이터타입임
    // int와 int *의 차이점은 무엇인가 ?
    // int number = 4;
    // int *pointer = &number;
    //
    // number의 메모리       4
    //    pointer        number
    player *player_object[MAX_PLAYER];
    char *name[MAX_PLAYER] = {
        "hello",
        "낵아마",
        "낵아뭐"
    };

    // dice 포인터를 관리한다는 것은 결론적으로 무엇을 관리하는 것인가 ?
    // dice 객체를 관리한다는 것
    dice *dice_array[MAX_PLAYER][MAX_DICE];

    printf("Eighth work\n");

    // 배열의 이름은 배열의 시작 주소고
    // 포인터는 주소를 저장하는 변수라는 것을 상기합시다.
    // player 객체에 name 정보 설정
    player_info_allocation(player_object, name);
    /*
    for (i = 0; i < MAX_PLAYER; i++)
    {
        player_object[i] = init_player_object();
        set_player_name(player_object[i], name[i]);
        print_player_object(player_object[i]);
    }
    */

    // 주사위 메모리(객체) 할당
    dice_memory_allocation(dice_array);
    /*
    random_seed_config();

    for (i = 0; i < MAX_PLAYER; i++)
    {
        for (j = 0; j < MAX_DICE; j++)
        {
            dice_array[i][j] = init_dice_object();
        }
    }
    */

    // 주사위 놀이 시작!
    play_dice_game(dice_array);

   /*
    for (i = 0; i < MAX_PLAYER; i++)
    {
        printf("player: %d\n", i);
        for (j = 0; j < MAX_DICE; j++)
        {
            bool isFirstDiceIsEven = false;
            if (j == SECOND_DICE)
            {
                // '!' 는 NOT 연산자로
                // 참을 부정하면 거짓
                // 거짓을 부정하면 참
                isFirstDiceIsEven = decision_even(
                        get_dice_number(dice_array[i][FIRST_DICE]));

                if (!isFirstDiceIsEven)
                {
                    break;
                }
            }

            roll_dice(dice_array[i][j]);
            print_dice_object(dice_array[i][j]);

            apply_dice_skill(isFirstDiceIsEven, dice_array, i);

            if (isFirstDiceIsEven)
            {
                int target_index;
                int second_dice = get_dice_number(
                    dice_array[i][SECOND_DICE]);

                switch (second_dice)
                {
                    case 2:
                        printf("2번 스킬: +3\n");
                        add_score(dice_array[i][SECOND_DICE]);
                        break;
                    
                    case 3:
                        printf("3번 스킬: -4\n");
                        target_index = find_target_dice(i);
                        sub_score(dice_array[target_index][SECOND_DICE]);
                        break;
                    
                    case 4:
                        printf("뒤졌음: -4444\n");
                        death(dice_array[i][SECOND_DICE]);
                        break;
                    
                    default:
                        break;
                }
            }
        }
    }
    */
    
    return 0;
}

void play_dice_game(dice *dice_array[MAX_PLAYER][MAX_DICE])
{
    int i, j;

    for (i = 0; i < MAX_PLAYER; i++)
    {
        printf("player: %d\n", i);
        for (j = 0; j < MAX_DICE; j++)
        {
            // 첫 번째 주사위가 짝수냐를 판정하기 위한 변수
            bool isFirstDiceIsEven = false;
            // 두 번째 주사위를 굴릴 때
            // decision_even과 get_dice_number를 통해
            // 첫 번째 주사위가 짝수인지 여부를 판정하여
            // isFirstDiceIsEven을 true, false로 만든다
            if (j == SECOND_DICE)
            {
                // '!' 는 NOT 연산자로
                // 참을 부정하면 거짓
                // 거짓을 부정하면 참
                isFirstDiceIsEven = decision_even(
                        get_dice_number(dice_array[i][FIRST_DICE]));

                // 홀수라면 더 이상 진행하지 않음
                if (!isFirstDiceIsEven)
                {
                    // 이 break의 경우 loop 1개를 탈출 할 수 있음
                    break;
                }
            }
            // check_first_dice_is_even(j, dice_array);

            // 첫 번째 주사위가 짝수임을 판정한 이후 두 번째 주사위가 굴러감
            // 첫 번째 주사위 또한 여기서 굴러감
            roll_dice(dice_array[i][j]);
            print_dice_object(dice_array[i][j]);

            apply_dice_skill(isFirstDiceIsEven, dice_array, i);
        }
    }
}