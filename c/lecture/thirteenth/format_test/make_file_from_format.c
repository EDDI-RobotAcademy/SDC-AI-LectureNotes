#include "make_file_from_format.h"

#include "../file_io/how_to_make_file.h"
#include "../file_io/how_to_write_content.h"

#include <stdio.h>
#include <fcntl.h>
#include <string.h>

#define BUDDY_PAGE_SIZE             4096

#define START_INDEX                 0

void adjust_write_contents_from_format(char *contents, test_form *format)
{
    int unique_id_size;
    int age_size;
    int major_length, self_introduction_length;

    // contents에 "id:%d,major:%s,age:%d,introduction:%s,\n" 의 형식으로 문자열을 생성함
    sprintf(contents, "id:%d,major:%s,age:%d,introduction:%s,\n", 
        format->unique_id, format->major, format->age, format->self_introduction);
    printf("contents: %s\n", contents);
}

bool write_format_to_file(test_form *format)
{
    char write_contents[BUDDY_PAGE_SIZE] = { 0 };

    // O_CREAT: 없으면 만듬
    // O_RDWR: Read/Write 모드
    // O_APPEND: 파일 내용의 후속 내용 덧붙이기 가능
    // O_TRUNC: 밀어버리기
    /* 0644
    $ ls -l
    total 64
    -rw-rw-r-- 1 eddi eddi 12122 11월 16 09:13 CMakeCache.txt
    drwxrwxr-x 5 eddi eddi  4096 11월 16 15:07 CMakeFiles
    -rw-rw-r-- 1 eddi eddi  1693 11월 16 09:13 cmake_install.cmake
    -rw-rw-r-- 1 eddi eddi  2577 11월 16 12:44 compile_commands.json
    -rw-rw-r-- 1 eddi eddi 12103 11월 16 12:44 Makefile
    -rwxrwxr-x 1 eddi eddi 26368 11월 16 15:07 test_app
    -rw-r--r-- 1 eddi eddi     0 11월 16 09:24 이거만들래.txt
    */
    int created_file_descriptor = file_open(
        "/home/eddi/proj/SDC-AI-LectureNotes/"
        "c/lecture/thirteenth/created_file/format_test.txt", 
            O_CREAT | O_RDWR | O_APPEND, 0644);

    adjust_write_contents_from_format(write_contents, format);

    write_content_in_file(created_file_descriptor, write_contents);

    file_close(created_file_descriptor);
}