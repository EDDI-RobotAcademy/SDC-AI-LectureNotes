#include "board_service_modify_handler.h"

#include "../../../../adapter/output/file/board_file_adapter.h"
//#include "../../../../adapter/output/file/handler/find_all/board_file_adapter_find_all_handler.h"
#include "../../../../adapter/output/file/board_file_adapter_table.h"

void board_service_modify(void)
{
    printf("board service: 게시물 정보를 수정합니다!\n");

    board_file_adapter_table[BOARD_FILE_ADAPTER_SAVE]();
}
