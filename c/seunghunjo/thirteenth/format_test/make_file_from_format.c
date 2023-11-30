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
    
    // constantsdp "sprintf(contents, "id:%d,major:%s,age:%d,introduction:%s,\n"형식으로 만들었음
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
    // 0644
    // 6이 rw권한자가 읽고 쓰기가능
    // 4 r 그이외는 읽기만 가능
    // 4 r 
    int created_file_descriptor = file_open(
        "/home/eddi/proj/SDC-AI-LectureNotes/"
        "c/seunghunjo/thirteenth/created_file/format_test.txt", 
            O_CREAT | O_RDWR | O_APPEND, 0644); 

    adjust_write_contents_from_format(write_contents, format);

    write_content_in_file(created_file_descriptor, write_contents);

    file_close(created_file_descriptor);
}