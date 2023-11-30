#ifndef __BOARD_MODEL_ID_H__
#define __BOARD_MODEL_ID_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _board_model_id board_model_id;

struct _board_model_id
{
    unsigned int board_id;
};

extern unsigned int board_id_unique_number;

board_model_id *init_board_model_id(void);
board_model_id *init_board_model_id_with_parameter(unsigned int);

unsigned int get_board_model_id(board_model_id *);
unsigned int increment_board_id_unique_number(void);

void clear_board_model_id(board_model_id *);

#ifdef __cplusplus
}
#endif

#endif