#include <gtest/gtest.h>
#include "../simple/add.h"

TEST(AddTest, onePlusTwoGivesThree)
{
    EXPECT_EQ(2, add(3,2));
}

TEST(한글도, 되냐)
{
    EXPECT_EQ(103, add(51,52));
}