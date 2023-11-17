#include <gtest/gtest.h>

#include "../../../../board/domain/model/board_model_title.h"

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

TEST(board_model_title, 게시물_수정시_제목_수정)
{
    char board_title[] = "제모기다!";
    char update_board_title[] = "수정간드앗!";
    int update_board_title_length = strlen(update_board_title);

    board_model_title *update_board_model_title_object;
    board_model_title *board_model_title_object =
        init_board_model_title_with_parameter(board_title);

    update_board_model_title_object = 
        update_board_model_title(board_model_title_object, update_board_title);

    

    EXPECT_NE(update_board_model_title_object, nullptr);
    EXPECT_TRUE(
        !strncmp(
            get_board_model_title(update_board_model_title_object), 
            update_board_title,
            update_board_title_length));
}