#include <stdio.h>
#include <stdbool.h>

#include "board/adapter/input/board_api.h"
#include "board/adapter/input/handler/board_api_handler.h"
#include "board/adapter/input/board_api_table.h"

#include "board/application/services/board_service.h"
#include "board/application/services/handler/board_service_handler.h"
#include "board/application/services/board_service_table.h"

void run_board_app(void)
{
    bool playerEnterQuit = false;

    while (!playerEnterQuit)
    {
        printf("첫 시작으로 게시판 리스트를 조회합니다!\n");
        board_api_table[BOARD_API_LIST]();
        break;
    }
}

int main (void)
{
    printf("C Based DDD Practice: Board\n");

    run_board_app();
    
    return 0;
}
