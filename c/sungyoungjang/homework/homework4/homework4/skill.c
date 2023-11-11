#include <stdio.h>

#include "skill.h"
#include "player.h"

void skill(int index, int first_dice, int* player_scores)
{
    random_config();
    /* 똑같은 것 두 개 배치 불가능
    int first_dice = roll_dice(0);
    int fitst_dice = roll_dice(1);
    */
    //int second_dice = roll_dice(0);
    //second_dice = roll_dice(1);

    player_scores[index] += first_dice;
    
    printf("index: %d\n", index);
    if (first_dice % 2 == 0)
    {
        /* 자신의 점수는 계산 안하고 상대 점수만 계산했음 */
        int second_dice = roll_dice(index);

        // 현재 자신의 점수를 계산한다.
        // 통짜로 만드는 것의 위험성 ... 로직 정리가 안됩니다.
        player_scores[index] += second_dice;

        printf("%d 번 플레이어의 두 번째 주사위 눈금은 %d\n", index, second_dice);
        if (second_dice == 2)
        {
            printf("%d 번 플레이어의 두 번째 주사위가 2가 나왔습니다. 자신의 주사위에 3을 더합니다.\n", index);
            player_scores[index] += 3;
        }
        else if (second_dice == 4)
        {
            printf("%d 번 플레이어의 두 번째 주사위가 4가 나왔습니다. 플레이어가 게임에서 탈락합니다.\n", index);
            player_scores[index] = -4444;
        }
        else if (second_dice == 3)
        {
            printf("%d 번 플레이어의 두 번째 주사위가 3이 나왔습니다. 상대편 점수에 -4를 공격합니다.\n", index);
            int score_index = (index == 0) ? 1 : 0;
            player_scores[score_index] -= 4;
        }
    }
   
    else
    {
        printf("%d 번 플레이어의 첫 번째 주사위가 홀수이므로 두 번째 주사위를 굴릴 수 없습니다.\n", index);
    }
}






