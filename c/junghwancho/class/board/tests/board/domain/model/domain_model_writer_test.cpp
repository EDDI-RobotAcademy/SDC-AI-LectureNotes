#include <gtest/gtest.h>

#include "../../../../board/domain/model/board_model_writer.h"

TEST(board_model_writer, 게시물_생성시_작성자_입력하지않음)
{
    board_model_writer *board_model_writer_object =
        init_board_model_writer_with_parameter(NULL);

    EXPECT_EQ(board_model_writer_object, nullptr);
}

TEST(board_model_writer, 게시물_생성시_작성자를_공백으로_입력하였음)
{
    char board_writer[] = "           \t";

    board_model_writer *board_model_writer_object =
        init_board_model_writer_with_parameter(board_writer);

    EXPECT_EQ(board_model_writer_object, nullptr);
}

TEST(board_model_writer, 게시물_생성시_작성자_글자수_제한을_초과하였음)
{
    char board_writer[] = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";

    board_model_writer *board_model_writer_object =
        init_board_model_writer_with_parameter(board_writer);

    EXPECT_EQ(board_model_writer_object, nullptr);
}

TEST(board_model_writer, 게시물_생성시_작성자_작성)
{
    char board_writer[] = "정상적인작성자";
    int board_writer_length = strlen(board_writer);

    board_model_writer *board_model_writer_object =
        init_board_model_writer_with_parameter(board_writer);

    EXPECT_NE(board_model_writer_object, nullptr);
    EXPECT_TRUE(
        !strncmp(
            get_board_model_writer(board_model_writer_object), 
            board_writer,
            board_writer_length));

    clear_board_model_writer(board_model_writer_object);
}
