#include <gtest/gtest.h>

#include "../../../../board/domain/model/board_model_info.h"

TEST(board_model_info, 게시물_생성시_게시물_정보_생성)
{
    char board_title[] = "제모기다!";
    char board_writer[] = "자크성자다";
    char board_content[] = "나는내용이다";

    board_model_title *board_model_title_object =
        init_board_model_title_with_parameter(board_title);

    board_model_writer *board_model_writer_object =
        init_board_model_writer_with_parameter(board_writer);

    board_model_content *board_model_content_object =
        init_board_model_content_with_parameter(board_content);

    board_model_info *board_model_info_object =
        init_board_model_info_with_parameter(
            board_model_title_object, 
            board_model_writer_object, 
            board_model_content_object);

    EXPECT_NE(board_model_info_object, nullptr);

    clear_board_model_info(board_model_info_object);
}

TEST(board_model_info, 게시물_생성시_게시물_정보_일부_누락)
{
    char board_title[] = "제모기다!";
    char board_writer[] = "";
    char board_content[] = "나는내용이다";

    board_model_title *board_model_title_object =
        init_board_model_title_with_parameter(board_title);

    board_model_writer *board_model_writer_object =
        init_board_model_writer_with_parameter(board_writer);

    board_model_content *board_model_content_object =
        init_board_model_content_with_parameter(board_content);

    board_model_info *board_model_info_object =
        init_board_model_info_with_parameter(
            board_model_title_object, 
            board_model_writer_object, 
            board_model_content_object);

    EXPECT_EQ(board_model_info_object, nullptr);
}

// TODO: Need to fix (Update Command)
TEST(board_model_info, 게시물_수정시_게시물_정보_누락)
{
    char board_title[] = "제모기다!";
    char board_writer[] = "자크성자다";
    char board_content[] = "나는내용이다";

    char new_board_title[] = "제목변경";
    char new_board_content[] = "내용변경";

    board_model_title *new_board_model_title_object;
    board_model_content *new_board_model_content_object;
    board_model_info *new_board_model_info_object;

    board_model_title *board_model_title_object =
        init_board_model_title_with_parameter(board_title);

    board_model_writer *board_model_writer_object =
        init_board_model_writer_with_parameter(board_writer);

    board_model_content *board_model_content_object =
        init_board_model_content_with_parameter(board_content);

    board_model_info *board_model_info_object =
        init_board_model_info_with_parameter(
            board_model_title_object, 
            board_model_writer_object, 
            board_model_content_object);

    new_board_model_title_object =
        init_board_model_title_with_parameter(new_board_title);

    new_board_model_content_object =
        init_board_model_content_with_parameter(new_board_content);

    new_board_model_info_object =
        update_board_model_info(
            board_model_info_object,
            new_board_model_title_object,
            new_board_model_content_object);

    EXPECT_NE(new_board_model_info_object, nullptr);

    clear_board_model_info(new_board_model_info_object);
}
