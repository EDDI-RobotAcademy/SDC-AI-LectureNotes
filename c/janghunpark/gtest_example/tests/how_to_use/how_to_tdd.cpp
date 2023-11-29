#include <gtest/gtest.h>

#include <stdio.h>

TEST(what_to_do, 나_ls_갈래)
{
    // 1. 일단 하고 싶은 것을 작성한다.
    int start = 1, end = 100;
    int result;
    int expected = 5050;

    // 2. 조지던 말던 원하는 형태를 작성한다.
    result = add_all_int_btw_start_and_end(start, end);

    // 3. 기대한 값을 예측한다.
    EXPECT_EQ(result, expected);
}

// 4. 당연히 기능이 없으니 초반에 터진다
// 5. 애초에 test에서 무엇을 하고 싶은지가 명시되므로 여기서 아젠다가 정리된다.
// 6. 해당 아젠다를 기반으로 위의 추상화된 형태가 구동되도록 작업한다.
// 7. 테스트가 통과되면 작업 완료다.
