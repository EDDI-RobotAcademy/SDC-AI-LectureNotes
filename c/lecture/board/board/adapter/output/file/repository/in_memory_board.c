#include "in_memory_board.h"

#include <stdlib.h>
#include <string.h>

in_memory_board *init_in_memory_board_object(unsigned int id, char *title, char *writer, char *content)
{
    int title_length, writer_length, content_length;
    in_memory_board *tmp_board = (in_memory_board *)malloc(sizeof(in_memory_board));

    title_length = strlen(title) + 1;
    writer_length = strlen(writer) + 1;
    content_length = strlen(content) + 1;

    tmp_board->id = id;
    tmp_board->title = (char *)malloc(sizeof(char) * title_length);
    tmp_board->writer = (char *)malloc(sizeof(char) * writer_length);
    tmp_board->content = (char *)malloc(sizeof(char) * content_length);

    strncpy(tmp_board->title, title, title_length);
    strncpy(tmp_board->writer, writer, writer_length);
    strncpy(tmp_board->content, content, content_length);

    return tmp_board;
}

void clear_in_memory_board_object(in_memory_board *object)
{
    free(object->title);
    free(object->writer);
    free(object->content);
    
    free(object);
}