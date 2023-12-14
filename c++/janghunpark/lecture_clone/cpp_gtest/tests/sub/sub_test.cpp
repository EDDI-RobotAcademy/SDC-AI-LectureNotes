//
// Created by eddi on 23. 12. 14.
//

#include <gtest/gtest.h>
#include "../../arithmetic/Sub.h"

TEST(SubTest, fourMinusTwoGivesThree)
{
    Sub *sub_object = new Sub();

    EXPECT_EQ(3, sub_object->difference(4, 2));
}