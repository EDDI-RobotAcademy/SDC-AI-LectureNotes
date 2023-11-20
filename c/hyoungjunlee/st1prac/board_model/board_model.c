#include "board_model.h"
 BOARD* create_board(void)
{
    int ALL_BOARD_COUNT;
    BOARD* tmp_BOARD= (BOARD*)malloc(sizeof(BOARD)*ALL_BOARD_COUNT);
    return tmp_BOARD;
}
//BOARD 구조체 동적할당