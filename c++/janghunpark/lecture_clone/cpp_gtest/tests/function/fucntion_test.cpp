//
// Created by eddi on 23. 12. 14.
//

#include <gtest/gtest.h>
#include "../../function/SampleFunction.h"

TEST(SampleFunctionTest, functionExecution)
{
    SampleFunction *testFunctionObject = new SampleFunction();

    EXPECT_EQ(testFunctionObject->testFucntion(-1), true);
    EXPECT_EQ(testFunctionObject->isRegisterSuccessed("나는 진짜 졸라게 긴 아이디", "나는 진짜 졸라게 긴 패스워드"), false);
}