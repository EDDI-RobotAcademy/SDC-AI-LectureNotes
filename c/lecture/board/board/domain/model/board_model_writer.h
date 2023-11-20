#ifndef __BOARD_MODEL_WRITER_H__
#define __BOARD_MODEL_WRITER_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _board_model_writer board_model_writer;

#define MAX_WRITER_LENGTH            32

struct _board_model_writer
{
    char board_writer[MAX_WRITER_LENGTH];
};

board_model_writer *init_board_model_writer_with_parameter(char *);
char *get_board_model_writer(board_model_writer *);
void clear_board_model_writer(board_model_writer *);

#ifdef __cplusplus
}
#endif

#endif