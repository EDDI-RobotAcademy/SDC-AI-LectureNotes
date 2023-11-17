#ifndef __BOARD_MODEL_TITLE_H__
#define __BOARD_MODEL_TITLE_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _board_model_title board_model_title;

#define MAX_TITLE_LENGTH            32

struct _board_model_title
{
    char board_title[MAX_TITLE_LENGTH];
};

board_model_title *init_board_model_title_with_parameter(char *);
board_model_title *update_board_model_title(char *);

#ifdef __cplusplus
}
#endif

#endif