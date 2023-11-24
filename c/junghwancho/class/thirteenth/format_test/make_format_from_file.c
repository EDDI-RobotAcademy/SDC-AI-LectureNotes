#include "make_format_from_file.h"

#include "../file_io/how_to_read_content.h"
#include "../file_io/how_to_make_file.h"

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define BUDDY_PAGE_SIZE         4096

int file_total_length (int file_descriptor)
{
    //lseek의 리턴 값은 두 번째 인자부터 3번째 인자까지 file pointer를 이동한 숫자
    return lseek(file_descriptor, 0, SEEK_END);
}

int find_enter_line_for_format_count(char *buffer, int total_length)
{
    int i;
    int count = 0;

    for (i = 0; i < total_length; i++)
    {
        if (!strncmp(&buffer[i], "\\n", 1)) // 비교 대상, 비교 대상, 비교 갯수
        // 두개가 같으면 false = 0, count 증가
        {
            count++;
        }
    }

    return count;
}

test_form **set_test_form_with_read_contents(
    test_form **test_format_array, int object_count, char *read_contents)
{
    int i;
    int field_count = 0;
    char major[32];
    char introduction[128];
    int age;
    unsigned int unique_id;

    int start, finish;
    bool started = false;
    int read_contents_length = strlen(read_contents);

    // 읽은 내용을 1 바이트씩 순회
    for (i = 0; i < read_contents_length; i++)
    {
        // ":" 찾기
        // 왜 찾는가 ?
        // format이 아래와 같으니까
        // id:1, major:시고르원조,age:20,introduction:낵아 시고르원조다!
        if (!started && !strncmp(&read_contents[i], ":", 1))
        {
            start = i;
            started = true;
        }

        // "," 찾기
        if (started && !strncmp(&read_contents[i], ",", 1))
        {
            finish = i;
            started = false;
            printf("start = %d, finish = %d\n", start, finish);

            // for (i = 0; i < object_count; i++)
            // {
            //     test_format_array[i] = init_test_form(major, age, introduction);
            // }

            // ":" 과 "," 사이의 값이 객체에 배치해야하는 정보임
            if (field_count % 4 == 0)
            {
                char tmp_str[32] = { 0 };
                strncpy(tmp_str, &read_contents[start + 1], finish - start - 1);
                unique_id = atoi(tmp_str); // ASKII TOOL INTIGER ex) 0이라는 문자가 있으면 진짜 0으로 바꿔줌 =반대는 sprintf
                printf("unique_id = %d\n", unique_id);
            }

            if (field_count % 4 == 1)
            {
                char tmp_str[32] = { 0 };
                memset(major, 0x00, 32); 
                // major 배열이 기존 정보를 유지하고 있을 가능성이 있으므로 전체 배열을 0 으로 초기화 시키는 작업 32bytes 만큼 초기화
                // #define으로 상수 값을 넣지 않도록 짜는게 깔끔할 듯
                // finish = ':' start = ',' 이므로 그 사이에 있는 값을 찾는 구조
                // +1, -1 하는 이유는 ':'의 뒤 ',' 앞의 값 부터 이용하겠다.
                strncpy(major, &read_contents[start + 1], finish - start - 1);
                printf("major = %s\n", major);
            }

            if (field_count % 4 == 2)
            {
                char tmp_str[32] = { 0 };
                strncpy(tmp_str, &read_contents[start + 1], finish - start - 1);
                age = atoi(tmp_str);
                printf("age = %d\n", age);
            }

            if (field_count % 4 == 3)
            {
                char tmp_str[128] = { 0 };
                memset(introduction, 0x00, 128);
                strncpy(introduction, &read_contents[start + 1], finish - start - 1);
                printf("itroduction: %s\n", introduction);

                test_format_array[field_count / 4] = 
                    init_test_form_with_id(unique_id, major, age, introduction);
            }

            // if (field_count % 4 == 0) {
            //     test_format_array[field_count++ / 4] 
            // }

            field_count++;
        }
    }

    return test_format_array;
}

test_form **read_file_to_format(void) // 파일을 읽어서 list를 만들어줌
{
    char read_contents[BUDDY_PAGE_SIZE] = { 0 };
    int object_count;
    int total_length;

    test_form **test_format_array;


    // O_RDONLY: 읽기 전용으로 열었음
    int created_file_descriptor = file_open(
        "/home/eddi/proj/SDC-AI-LectureNotes/"
        "c/junghwancho/class/thirteenth/created_file/format_test.txt", 
            O_RDONLY, 0644);

    //read_content_from_file_and_print(created_file_descriptor, read_contents);
    read_content_from_file(created_file_descriptor, read_contents);
    printf("read_contents: %s\n", read_contents); // 읽은 내용 확인

    total_length = file_total_length(created_file_descriptor); // 파일 total_length 값을 뽑아옴
    file_close(created_file_descriptor); // 열어둘 필요 없으니 close

    object_count = find_enter_line_for_format_count(read_contents, total_length); 
    // enter 갯수 만큼 line 이 있기 때문에 몇 개의 객체를 만들어야 하는지 판정하기 위해 enter line 찾음
    test_format_array = init_test_form_array(object_count);// 학생 객체를 관리할 수 있는 배열을 만듬
    printf("object_count: %d\n", object_count);

    test_format_array = set_test_form_with_read_contents(test_format_array, object_count, read_contents);
    printf("test_format_array: 0x%x\n", test_format_array);
}