#include "board_service_create_request.h"

#include <stdlib.h>
#include <string.h>

board_service_create_request *init_board_service_create_request(
        char *title, char *writer, char *content)
{
    int title_length, writer_length, content_length;

    if (title == NULL) { return NULL; }

    board_service_create_request *tmp_request = (board_service_create_request *)
        malloc(sizeof(board_service_create_request));

    title_length = strlen(title);
    writer_length = strlen(writer);
    content_length = strlen(content);

    tmp_request->title = (char *)malloc(sizeof(char) * title_length);
    tmp_request->writer = (char *)malloc(sizeof(char) * writer_length);
    tmp_request->content = (char *)malloc(sizeof(char) * content_length);

    strncpy(tmp_request->title, title, title_length);
    strncpy(tmp_request->writer, writer, writer_length);
    strncpy(tmp_request->content, content, content_length);

    return tmp_request;
}

char *get_board_service_create_request_title(board_service_create_request *object)
{
    return object->title;
}

char *get_board_service_create_request_writer(board_service_create_request *object)
{
    return object->writer;
}

char *get_board_service_create_request_content(board_service_create_request *object)
{
    return object->content;
}

void clear_board_service_create_request(board_service_create_request *origin)
{
    free(origin->title);
    free(origin->writer);
    free(origin->content);

    free(origin);
}
