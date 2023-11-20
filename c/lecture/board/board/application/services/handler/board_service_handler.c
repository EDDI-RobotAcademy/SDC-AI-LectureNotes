#include "board_service_handler.h"

#include <stdio.h>

#include "../../../adapter/output/file/board_file_adapter.h"
#include "../../../adapter/output/file/handler/board_file_adapter_handler.h"
#include "../../../adapter/output/file/board_file_adapter_table.h"

void board_service_get_list(void)
{
    printf("board service: 게시판 리스트를 획득합니다!\n");

    board_file_adapter_table[BOARD_FILE_ADAPTER_FIND_ALL]();
}
