//
// Created by eddi on 23. 12. 4.
//

#include <gtest/gtest.h>
#include "../../arithmetic/Add.h"

TEST(AddTest, onePlusTwoGivesThree)
{
    Add *add_object = new Add();

    EXPECT_EQ(3, add_object->sum(1, 2));
}