#include "board_service_remove_handler.h"

#include <stdio.h>

#include "../../../../adapter/output/file/board_file_adapter.h"
//#include "../../../../adapter/output/file/handler/find_all/board_file_adapter_find_all_handler.h"
#include "../../../../adapter/output/file/board_file_adapter_table.h"

void board_service_remove(void *request)
{
    printf("board service: 게시물을 삭제합니다!\n");

    board_file_adapter_table[BOARD_FILE_ADAPTER_DELETE](request);
}
