#include "board_service_create_response.h"

#include <stdlib.h>
#include <string.h>

board_service_create_response *init_board_service_create_response(
        unsigned int id, char *title, char *writer, char *content)
{
    int title_length, writer_length, content_length;

    board_service_create_response *tmp_response = (board_service_create_response *)
        malloc(sizeof(board_service_create_response));

    title_length = strlen(title);
    writer_length = strlen(writer);
    content_length = strlen(content);

    tmp_response->id = id;
    tmp_response->title = (char *)malloc(sizeof(char) * title_length);
    tmp_response->writer = (char *)malloc(sizeof(char) * writer_length);
    tmp_response->content = (char *)malloc(sizeof(char) * content_length);

    strncpy(tmp_response->title, title, title_length);
    strncpy(tmp_response->writer, writer, writer_length);
    strncpy(tmp_response->content, content, content_length);

    return tmp_response;
}

char *get_board_service_create_response_title(board_service_create_response *object)
{
    return object->title;
}

char *get_board_service_create_response_writer(board_service_create_response *object)
{
    return object->writer;
}

char *get_board_service_create_response_content(board_service_create_response *object)
{
    return object->content;
}

void clear_board_service_create_response(board_service_create_response *origin)
{
    free(origin->title);
    free(origin->writer);
    free(origin->content);

    free(origin);
}

void print_board_service_response(board_service_create_response *object)
{
    printf("\033[1;34m%-8s%-25s%-15s\033[0m\n", "번호", "제목", "작성자");
    printf("==========================================\n");
    printf("\033[1;32m%-6d%-25.*s%-15.*s\033[0m\n",
        object->id, 25, object->title, 15, object->writer);
    printf("\033[1;33m================== 내용 ==================\033[0m\n");
    printf("\033[1;33m%s\033[0m\n", object->content);
}
