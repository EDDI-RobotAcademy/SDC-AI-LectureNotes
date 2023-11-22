#include <gtest/gtest.h>
#include "../simple/sub.h"

TEST(뺄셈, 빼기이)
{
    EXPECT_EQ(-1, sub(1, 2));
}
