#include <gtest/gtest.h>
#include "../simple/sub.h"

TEST(뺄셈_테스트, 첫번째_빼기_두번째)
{
    EXPECT_EQ(-1, sub(1, 2));
}