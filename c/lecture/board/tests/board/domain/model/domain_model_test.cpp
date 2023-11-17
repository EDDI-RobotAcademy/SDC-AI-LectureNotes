#include <gtest/gtest.h>

#include "../../../../board/domain/model/board_model_id.h"

TEST(게시물_번호_객체, 게시물_생성시_번호_생성)
{
    int current_board_model_id;
    board_model_id *board_model_id_object = init_board_model_id();
    current_board_model_id = get_board_model_id(board_model_id_object);
    
    EXPECT_NE(board_model_id_object, nullptr);
    EXPECT_EQ(current_board_model_id, 0);
}