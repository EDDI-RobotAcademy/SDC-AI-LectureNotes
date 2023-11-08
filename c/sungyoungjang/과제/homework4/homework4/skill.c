#include <stdio.h>
#include "skill.h"
#include "player.h"


void skill(int index, int first_dice, int* player_scores)
{
    random_config();
    int first_dice = roll_dice(0);
    int fitst_dice = roll_dice(1);
    
    if (first_dice % 2 == 0)
    {
       
        int second_dice = roll_dice(index);
        printf("%d 번 플레이어의 두 번째 주사위 눈금은 %d\n", index, second_dice);
        if (second_dice == 2)
        {
            printf("%d 번 플레이어의 두 번째 주사위가 2가 나왔습니다. 자신의 주사위에 3을 더합니다.\n", index);
            player_scores[index] += 3;
        }
        else if (second_dice == 4)
        {
            printf("%d 번 플레이어의 두 번째 주사위가 4가 나왔습니다. 플레이어가 게임에서 탈락합니다.\n", index);
            
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






