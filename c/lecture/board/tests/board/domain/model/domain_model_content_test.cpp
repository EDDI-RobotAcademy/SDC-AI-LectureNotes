#include <gtest/gtest.h>

#include <string.h>

#include "../../../../board/domain/model/board_model_content.h"

TEST(board_model_content, 게시물_생성시_내용_입력하지않음)
{
    board_model_content *board_model_content_object =
        init_board_model_content_with_parameter(NULL);

    EXPECT_EQ(board_model_content_object, nullptr);
}

TEST(board_model_content, 게시물_생성시_내용을_공백으로_입력하였음)
{
    char board_content[] = "           \t";

    board_model_content *board_model_content_object =
        init_board_model_content_with_parameter(board_content);

    EXPECT_EQ(board_model_content_object, nullptr);
}

TEST(board_model_content, 게시물_생성시_내용_글자수_제한을_초과하였음)
{
    char board_content[MAX_CONTENT_LENGTH + 1] = { 0 };
    memset(board_content, 0x65, MAX_CONTENT_LENGTH + 1);

    board_model_content *board_model_content_object =
        init_board_model_content_with_parameter(board_content);

    EXPECT_EQ(board_model_content_object, nullptr);
}

TEST(board_model_content, 게시물_수정시_내용_수정)
{
    char board_content[] = "제모기다!";
    char update_board_content[] = "수정간드앗!";
    int update_board_content_length = strlen(update_board_content);

    board_model_content *update_board_model_content_object;
    board_model_content *board_model_content_object =
        init_board_model_content_with_parameter(board_content);

    update_board_model_content_object = 
        update_board_model_content(board_model_content_object, update_board_content);

    EXPECT_NE(update_board_model_content_object, nullptr);
    EXPECT_TRUE(
        !strncmp(
            get_board_model_content(update_board_model_content_object), 
            update_board_content,
            update_board_content_length));

    clear_board_model_content(update_board_model_content_object);
}

TEST(board_model_content, 게시물_생성시_내용_작성)
{
    char board_content[] = "정상적인제목";
    int board_content_length = strlen(board_content);

    board_model_content *board_model_content_object =
        init_board_model_content_with_parameter(board_content);

    EXPECT_NE(board_model_content_object, nullptr);
    EXPECT_TRUE(
        !strncmp(
            get_board_model_content(board_model_content_object), 
            board_content,
            board_content_length));

    clear_board_model_content(board_model_content_object);
}
