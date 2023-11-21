#include "board_api_remove_handler.h"

#include "../../../../application/services/board_service.h"
#include "../../../../application/services/handler/remove/board_service_remove_handler.h"
#include "../../../../application/services/board_service_table.h"

#include <stdio.h>

void board_api_remove(void)
{
    printf("board api: 게시물을 삭제합니다!\n");

    board_service_table[BOARD_SERVICE_REMOVE]();
}