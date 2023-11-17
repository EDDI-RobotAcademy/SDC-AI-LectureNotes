#include <gtest/gtest.h>

#include "../../../../board/domain/model/board_model_id.h"
#include "../../../../board/domain/model/board_model_title.h"

TEST(board_model_id, 게시물_생성시_번호_생성)
{
    int current_board_model_id;
    board_model_id *board_model_id_object = init_board_model_id();
    current_board_model_id = get_board_model_id(board_model_id_object);
    
    EXPECT_NE(board_model_id_object, nullptr);
    EXPECT_EQ(current_board_model_id, 0);

    clear_board_model_id(board_model_id_object);
}

TEST(board_model_id, 게시물_생성시_번호_주입)
{
    int created_board_id;
    int injection_board_id = 3;
    board_model_id *board_model_id_object = 
        init_board_model_id_with_parameter(injection_board_id);

    created_board_id = get_board_model_id(board_model_id_object);

    EXPECT_NE(board_model_id_object, nullptr);
    EXPECT_EQ(created_board_id, injection_board_id);

    clear_board_model_id(board_model_id_object);
}

TEST(board_model_title, 게시물_생성시_제목_입력하지않음)
{
    board_model_title *board_model_title_object =
        init_board_model_title_with_parameter(NULL);

    EXPECT_EQ(board_model_title_object, nullptr);
}

TEST(board_model_title, 게시물_생성시_제목을_공백으로_입력하였음)
{
    char board_title[] = "           \t";

    board_model_title *board_model_title_object =
        init_board_model_title_with_parameter(board_title);

    EXPECT_EQ(board_model_title_object, nullptr);
}

TEST(board_model_title, 게시물_생성시_제목_글자수_제한을_초과하였음)
{
    char board_title[] = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";

    board_model_title *board_model_title_object =
        init_board_model_title_with_parameter(board_title);

    EXPECT_EQ(board_model_title_object, nullptr);
}