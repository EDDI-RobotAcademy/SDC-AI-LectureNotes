#include <gtest/gtest.h>

#include <stdio.h>

#include "../../sample/sample.h"

TEST(what_do_you_want_to_do, 무엇을_하고_싶니)
{
    // 1. 일단 그냥 하고 싶은 것을 작성한다.
    int start = 1, end = 100;
    int expected = 5050;
    int result;

    // 2. 조지던 말던 원하는 형태를 작성한다.
    result = add_all_to_end_from_start(start, end);
    printf("result = %d\n", result);

    // 3. 기대한 값을 예측한다.
    EXPECT_EQ(result, expected);
}

// 4. 당연히 기능이 없으니 초반에 터진다.
// 5. 애초에 test에서 무엇을 하고 싶은지가 명시되므로 여기서 아젠다가 정리된다.
// 6. 해당 아젠다를 기반으로 위의 추상화된 형태가 구동되도록 작업한다.
// 7. 테스트가 통과되면 작업 완료다.

TEST(what_do_you_want_to_do, 구조체_정보를_기입할_때_내용이_누락되었음)
{
    char name[MAX_USER_LENGTH] = "이름이야";
    char phone[MAX_PHONE_LENGTH] = { 0 };

    for_test_struct *test_object;

    test_object = init_for_test_struct_object(name, phone);

    // 내용 누락이 있으므로 생성하면 안됨
    EXPECT_EQ(test_object, nullptr);
}

TEST(what_do_you_want_to_do, 구조체_정보를_기입할_때_내용이_정상적으로_입력되었음)
{
    char name[MAX_USER_LENGTH] = "이름이야";
    char phone[MAX_PHONE_LENGTH] = "010-1111-2222";

    int name_length = strlen(name);
    int phone_length = strlen(phone);

    for_test_struct *test_object;

    test_object = init_for_test_struct_object(name, phone);

    // 내용 누락이 있으므로 생성하면 안됨
    EXPECT_NE(test_object, nullptr);
    EXPECT_TRUE(!strncmp(get_for_test_struct_name(test_object), name, name_length));
    EXPECT_TRUE(!strncmp(get_for_test_struct_phone(test_object), phone, phone_length));

    clear_for_test_struct_object(test_object);
}