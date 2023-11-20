#include <gtest/gtest.h>
#include "../simple/add.h"

// 일부러 조지는 케이스를 적고 동작을 하는지 검사
// 사고 예방 차원
// 도메인을 찾는데 도움이 된다.
TEST(AddTest, onePlusTwoGivesThree)
{
    EXPECT_EQ(7, add(3, 4));
}

TEST(AddTest, 나는야_덧셈)
{
    EXPECT_EQ(9, add(3, 6));
}