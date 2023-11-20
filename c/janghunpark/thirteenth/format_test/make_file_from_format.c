#include "make_file_from_format.h"

#include "../file_io/how_to_make_file.h"
#include "../file_io/how_to_write_content.h"

#include <fcntl.h>
#include <string.h>

#define BUDDY_PAGE_SIZE     4096

#define START_INDEX         0

void adjust_write_contents_from_format(char *contents, test_form *format)
{
    int unique_id_size;
    int age_size;
    int major_length, self_introduction_length;

    sprintf(contents, "id: %d, major: %s, age: %d, self introduction: %s",
        format->unique_id, format->major, format->age, format->self_introduction);
    printf("contents: %s\n", contents);

    unique_id_size = sizeof(format->unique_id);
    memcpy(&contents[START_INDEX], &format->unique_id, sizeof(format->unique_id));

    major_length = strlen(format->major);
    memcpy(&contents[START_INDEX + unique_id_size], format->major, major_length);

    age_size = sizeof(format->age);
    memcpy(&contents[START_INDEX + unique_id_size + major_length], &format->age, age_size);

    self_introduction_length = strlen(format->self_introduction);
    memcpy(&contents[START_INDEX + unique_id_size + major_length + self_introduction_length], 
        format->self_introduction, self_introduction_length);
}

bool write_format_to_file(test_form *format)
{
    char write_contents[BUDDY_PAGE_SIZE] = { 0 };
   
    int created_file_descriptor = file_open(
        "/home/eddi/proj/SDC-AI-LectureNotes/c/janghunpark/thirteenth/created_file/format_test.txt", 
            O_CREAT | O_RDWR | O_TRUNC, 0644);

    adjust_write_contents_from_format(write_contents, format);

    write_content_in_file(created_file_descriptor, write_contents);

    file_close(created_file_descriptor);
}