#include "board_service_get_list_handler.h"

#include <stdio.h>

#include "../../../../adapter/output/file/board_file_adapter.h"
#include "../../../../adapter/output/file/handler/find_all/board_file_adapter_find_all_handler.h"
#include "../../../../adapter/output/file/board_file_adapter_table.h"

#include "../../../../adapter/output/file/repository/in_memory_board_manager.h"
#include "../../../../application/services/response/list/board_service_list_response.h"

#include <stdlib.h>

void *board_service_get_list(void *request)
{
    int i;
    int total_count;
    in_memory_board *in_memory_board_array;
    board_service_list_response **list_response;
    //board_service_list_response *list_response;

    printf("board service: 게시판 리스트를 획득합니다!\n");

    in_memory_board_array = board_file_adapter_table[BOARD_FILE_ADAPTER_FIND_ALL](NULL);
    total_count = global_in_memory_board_manager.alloc_count;

    list_response = (board_service_list_response **)
        malloc(sizeof(board_service_list_response *) * total_count);

    printf("board service list: total_count = %d\n", total_count);

    for (i = 0; i < total_count; i++)
    {
        list_response[i] = (board_service_list_response *)
            malloc(sizeof(board_service_list_response));

        printf("list_response_array: %d\n", i);

        list_response[i] = init_board_service_list_response(
            get_in_memory_board_id(
                &in_memory_board_array[i]
            ),
            get_in_memory_board_title(
                &in_memory_board_array[i]
            ),
            get_in_memory_board_writer(
                &in_memory_board_array[i]
            )
        );
    }

    printf("Success to construct board service list response\n");

    return list_response;
}
