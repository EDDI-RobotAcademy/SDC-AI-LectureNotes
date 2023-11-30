#ifndef __BOARD_FILE_IN_MEMORY_REPOSITORY_H__
#define __BOARD_FILE_IN_MEMORY_REPOSITORY_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <sys/stat.h>
#include <time.h>

typedef struct _in_memory_board in_memory_board;

struct _in_memory_board
{
    unsigned int id;

    char *title;
    char *writer;
    char *content;

    time_t creation_time;
    time_t updated_time;
};

in_memory_board *init_in_memory_board_object(unsigned int, char *, char *, char *);
void alloc_memory_board_object(in_memory_board *, unsigned int, char *, char *, char *);

unsigned int get_in_memory_board_id(in_memory_board *);
char *get_in_memory_board_title(in_memory_board *);
char *get_in_memory_board_writer(in_memory_board *);
char *get_in_memory_board_content(in_memory_board *);

void clear_in_memory_board_object(in_memory_board *);

#ifdef __cplusplus
}
#endif

#endif