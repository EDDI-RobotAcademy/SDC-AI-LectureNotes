#include "board_service_list_response.h"

#include <stdlib.h>
#include <string.h>

#include "../../../../adapter/output/file/repository/in_memory_board_manager.h"

board_service_list_response *init_board_service_list_response(
        unsigned int id, char *title, char *writer)
{
    int title_length, writer_length;

    board_service_list_response *tmp_response = (board_service_list_response *)
        malloc(sizeof(board_service_list_response));

    title_length = strlen(title);
    writer_length = strlen(writer);

    tmp_response->id = id;
    tmp_response->title = (char *)malloc(sizeof(char) * title_length);
    tmp_response->writer = (char *)malloc(sizeof(char) * writer_length);

    strncpy(tmp_response->title, title, title_length);
    strncpy(tmp_response->writer, writer, writer_length);

    return tmp_response;
}

char *get_board_service_list_response_id(board_service_list_response *object)
{
    return object->id;
}
char *get_board_service_list_response_title(board_service_list_response *object)
{
    return object->title;
}

char *get_board_service_list_response_writer(board_service_list_response *object)
{
    return object->writer;
}

void clear_board_service_list_response(board_service_list_response *origin)
{
    free(origin->title);
    free(origin->writer);

    free(origin);
}

void print_board_service_list_response(board_service_list_response **object_array)
{
    int i;
    int total_length = global_in_memory_board_manager.alloc_count;

    printf("%-8s%-25s%-15s\n", "번호", "제목", "작성자");
    printf("=========================================\n");

    for (i = 0; i < total_length; i++)
    {
        printf("%-6d%-25s%-15s\n",
            object_array[i]->id, object_array[i]->title, object_array[i]->writer);
    }
}
