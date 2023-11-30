#ifndef __BOARD_MODEL_CONTENT_H__
#define __BOARD_MODEL_CONTENT_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _board_model_content board_model_content;

#define MAX_CONTENT_LENGTH          8192

struct _board_model_content
{
    char board_content[MAX_CONTENT_LENGTH];
};

board_model_content *init_board_model_content_with_parameter(char *);
board_model_content *update_board_model_content(board_model_content *, char *);
char *get_board_model_content(board_model_content *);
void clear_board_model_content(board_model_content *);

#ifdef __cplusplus
}
#endif

#endif