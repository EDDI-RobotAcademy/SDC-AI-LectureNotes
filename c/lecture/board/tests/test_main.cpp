#include <gtest/gtest.h>

// 삭제 이후 생성 이후 다시 전체 조회
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
