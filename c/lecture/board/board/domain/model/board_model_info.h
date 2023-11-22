#ifndef __BOARD_MODEL_INFO_H__
#define __BOARD_MODEL_INFO_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "board_model_title.h"
#include "board_model_writer.h"
#include "board_model_content.h"

typedef struct _board_model_info board_model_info;

struct _board_model_info
{
    board_model_title *board_model_title;
    board_model_writer *board_model_writer;
    board_model_content *board_model_content;
};

board_model_info *init_board_model_info_with_parameter(
    board_model_title *, board_model_writer *, board_model_content *);

board_model_info *update_board_model_info(
    board_model_info *, board_model_title *, board_model_content *);

board_model_writer *get_board_model_writer_from_model_info(board_model_info *);

void clear_board_model_info(board_model_info *);

#ifdef __cplusplus
}
#endif

#endif