#ifndef __BOARD_MODEL_H__
#define __BOARD_MODEL_H__
#define TITLE_LIMIT 32
#define CONTENT_LIMET 512
#define WRTITER_LIMIT 16
extern int ALL_BOARD_COUNT = 1;

typedef struct _BOARD BOARD;
struct _BOARD
{
    int check_board_num;
    char title[TITLE_LIMIT];
    char content[CONTENT_LIMET];
    char writer[WRTITER_LIMIT];
};
#endif