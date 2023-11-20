#include "board_service_create_handler.h"

#include <stdio.h>

#include "../../../../adapter/output/file/board_file_adapter.h"
#include "../../../../adapter/output/file/handler/board_file_adapter_handler.h"
#include "../../../../adapter/output/file/board_file_adapter_table.h"

void board_service_create(void)
{
    printf("board service: 게시물을 생성합니다!\n");

    board_file_adapter_table[BOARD_FILE_ADAPTER_SAVE]();
}
