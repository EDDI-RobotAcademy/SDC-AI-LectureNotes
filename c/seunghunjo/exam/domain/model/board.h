#ifndef __BOARD_H__
#define __BOARD_H__

extern int id_count;

typedef struct _board board;

struct _board
{
    int unique_id;
    char *title;
    char *writer;
    char *detail;
};


board *init_board_model_object(void);




#endif