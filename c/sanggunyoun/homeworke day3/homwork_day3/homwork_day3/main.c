#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int player1_score = 0, player2_score = 0;
    srand(time(NULL)); 

    
    int dice = rand() % 6 + 1;
    printf("Player 1 rolled %d\n", dice);
       

        if (dice == 1 || dice == 2 || dice == 5 || dice == 6) {
            player1_score += dice + 3;
        }
    if (dice == 2 || dice == 6) {
        dice = rand() % 6 + 1;
        printf("Player 1 rolled %d on second roll\n", dice);
            

            if (dice == 4) {
                printf("Player 1 rolled a 4 on second roll. Game over. Player 2 wins!\n");
                    
                    return 0;
            }
        if (dice == 3) {
            player1_score += 3;
            player2_score -= 4;
        }
    }

    
    dice = rand() % 6 + 1;
    printf("Player 2 rolled %d\n", dice);
        

        if (dice == 1 || dice == 2 || dice == 5 || dice == 6) {
            player2_score += dice + 3;
        }
    if (dice == 2 || dice == 6) {
        dice = rand() % 6 + 1;
        printf("Player 2 rolled %d on second roll\n", dice);
            
        //이게 더 위로 올라가야 할것같다
            if (dice == 4) {
                printf("Player 2 rolled a 4 on second roll. Game over. Player 1 wins!\n");
                    
                    return 0;
            }
        if (dice == 3) {
            player2_score += 3;
            player1_score -= 4;
        }
    }

  
    if (player1_score > player2_score) {
        printf("Player 1's score: %d, Player 2's score: %d\n", player1_score, player2_score);
            
            printf("Player 1 wins!\n");
                
    }
    else if (player1_score < player2_score) {
        printf("Player 1's score: %d, Player 2's score: %d\n", player1_score, player2_score);
            
            printf("Player 2 wins!\n");
                
    }
    else {
        printf("Player 1's score: %d, Player 2's score: %d\n", player1_score, player2_score);
            
            printf("It's draw\n");
                
    }
    return 0;
}