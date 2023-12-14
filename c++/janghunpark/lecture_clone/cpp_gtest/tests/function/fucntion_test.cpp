//
// Created by eddi on 23. 12. 14.
//

#include <gtest/gtest.h>
#include "../../function/SampleFunction.h"

TEST(SampleFunctionTest, functionExecution)
{
    SampleFunction *testFunctionObject = new SampleFunction();

    EXPECT_EQ(testFunctionObject->testFucntion(-1), true);
}