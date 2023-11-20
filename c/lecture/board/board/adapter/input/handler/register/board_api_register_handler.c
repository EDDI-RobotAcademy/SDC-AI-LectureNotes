#include "board_api_register_handler.h"

#include "../../../../application/services/board_service.h"
#include "../../../../application/services/handler/create/board_service_create_handler.h"
#include "../../../../application/services/board_service_table.h"

#include <stdio.h>

void board_api_register(void)
{
    printf("board api: 게시물을 작성합니다!\n");

    board_service_table[BOARD_SERVICE_CREATE]();
}