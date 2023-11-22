#include <gtest/gtest.h>
#include <stdio.h>
#include <string.h>

#include "../../sample/sample.h"

TEST(이거, 저거)
{
   //1. 일단 하고싶은걸 작성한다.
   int start = 1, end = 190;

   int expected = 18145;
   int result;

   // 2. 조지던 말던 원하는 형태를 작성한다.
   result = add_all_start_to_end(start,end);

   // 3.기대한 값을 예측한다

   EXPECT_EQ(result, expected);

}

// 4. 당연히 기능이 없으니 초반에 셧다운된다
// 5. 애초에 test에서 무엇을 하고 싶은지가 명시되므로 여기서 어쩐다가 정리된다.
// 6. 해당 아젠다를 기반으로 위의 추상화된 형태가 구동되도록 작업한다.
// 7. 테스트가 통과되면 작업 완료이다.

TEST(백로그쓰자, 구조체_정보를_기입할때_정보가_누락됨)
{
    char name[MAX_USER_LENGTH] = {"aserwear"};
    char phone[MAX_PHONE_LENGTH] = {"011154245"};

    int name_len = strlen(name);
    int phone_len = strlen(phone);

    for_test_struct *test_object;

    test_object = init_for_test_struct_object(name,phone);
    
    // 내용 누락이 있으므로 생성하면 안됨
    EXPECT_EQ(test_object, nullptr);
    EXPECT_TRUE(!strncmp(get_name(test_object),name,name_len+1));
    EXPECT_TRUE(!strncmp(get_phone(test_object),phone,phone_len+1));

    clear_object(test_object);

    EXPECT_EQ(test_object, nullptr);
}