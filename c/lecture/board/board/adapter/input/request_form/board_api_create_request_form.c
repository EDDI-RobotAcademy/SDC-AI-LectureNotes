#include "board_api_create_request_form.h"

#include <stdlib.h>
#include <string.h>

board_api_create_request_form *init_board_api_create_request_form(
    char *title, char *writer, char *content)
{
    int title_length, writer_length, content_length;

    if (title == NULL) { return NULL; }

    board_api_create_request_form *tmp_request_form = (board_api_create_request_form *)
        malloc(sizeof(board_api_create_request_form));

    title_length = strlen(title);
    writer_length = strlen(writer);
    content_length = strlen(content);

    tmp_request_form->title = (char *)malloc(sizeof(char) * title_length);
    tmp_request_form->writer = (char *)malloc(sizeof(char) * writer_length);
    tmp_request_form->content = (char *)malloc(sizeof(char) * content_length);

    strncpy(tmp_request_form->title, title, title_length);
    strncpy(tmp_request_form->writer, writer, writer_length);
    strncpy(tmp_request_form->content, content, content_length);

    return tmp_request_form;
}

char *get_board_api_create_request_form_title(board_api_create_request_form *object)
{
    return object->title;
}

char *get_board_api_create_request_form_writer(board_api_create_request_form *object)
{
    return object->writer;
}

char *get_board_api_create_request_form_content(board_api_create_request_form *object)
{
    return object->content;
}

void clear_board_api_create_request_form(board_api_create_request_form *origin)
{
    free(origin->title);
    free(origin->writer);
    free(origin->content);

    free(origin);
}