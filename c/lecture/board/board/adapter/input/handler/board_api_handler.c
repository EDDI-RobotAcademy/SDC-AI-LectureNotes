#include "board_api_handler.h"

#include "../../../application/services/board_service.h"
#include "../../../application/services/handler/board_service_handler.h"
#include "../../../application/services/board_service_table.h"

#include <stdio.h>

void board_api_list(void)
{
    printf("board api: 게시판 리스트를 조회합니다!\n");

    board_service_table[BOARD_SERVICE_GET_LIST]();
}
