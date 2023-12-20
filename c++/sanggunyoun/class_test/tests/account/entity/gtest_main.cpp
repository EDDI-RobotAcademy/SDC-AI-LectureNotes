#include <gtest/gtest.h>
//  돌리고자 하는 경로
#include "../../../account/entity/Account.h"

TEST(accountEntity, createAccountEntity)
{
    auto *account = new Account("hi", "hello");

    // 통과
//    account->printAccountInfo();
     EXPECT_NE(account, nullptr);

    // 실패
//    EXPECT_EQ(account, nullptr);

    delete account;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
