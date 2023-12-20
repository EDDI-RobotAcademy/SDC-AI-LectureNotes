#include <gtest/gtest.h>
#include "../simple/add.h"

TEST(AddTest, onePlusTwoGivesThree)
{
    EXPECT_EQ(2, add(1, 2));
}

// ? 같은 특수 문자를 적지마세요.
TEST(덧셈_테스트, 이거_더하기_저거_되는거야)
{
    EXPECT_EQ(3, add(1, 2));
}