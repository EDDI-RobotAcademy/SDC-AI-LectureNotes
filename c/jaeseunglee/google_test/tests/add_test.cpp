#include <gtest/gtest.h>
#include "../simple/add.h"

TEST(AddTest, onePlusTwoGivesThree)
{
    EXPECT_EQ(5, add(1,2));
}