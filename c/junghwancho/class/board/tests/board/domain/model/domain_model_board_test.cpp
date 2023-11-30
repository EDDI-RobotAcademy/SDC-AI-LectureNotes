#include <gtest/gtest.h>

#include "../../../../board/domain/model/board_model.h"

TEST(board_model, 게시물_생성)
{
    char board_title[] = "제모기다!";
    char board_writer[] = "자크성자다";
    char board_content[] = "나는내용이다";

    board_model_id *board_model_id_object =
        init_board_model_id();

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

    board_model *board_model_object =
        init_board_model_with_parameter(
            board_model_id_object, 
            board_model_info_object);

    EXPECT_NE(board_model_object, nullptr);

    clear_board_model(board_model_object);
}

// TODO: 아직 수정 미완료
TEST(board_model, 게시물_수정)
{
    char board_title[] = "제모기다!";
    char board_writer[] = "자크성자다";
    char board_content[] = "나는내용이다";

    board_model_id *board_model_id_object =
        init_board_model_id();

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

    board_model *board_model_object =
        init_board_model_with_parameter(
            board_model_id_object, 
            board_model_info_object);

    EXPECT_NE(board_model_object, nullptr);

    clear_board_model(board_model_object);
}