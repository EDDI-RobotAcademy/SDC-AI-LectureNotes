#include <string.h>
#include <fcntl.h>
#include <stdio.h>


#include "make_file_from_format.h"

#include "../file_io/how_to_make_file.h"
#include "../file_io/how_to_write_content.h"
#include "../file_io/how_to_read_content.h"

#define BUDDY_PAGE_SIZE (4096)

#define START_INDEX     0

void adjust_write_contents_from_format(char *contents, test_form *format)
{
    int unique_id_size, age_size;
    int major_length, self_introduction_legth;

     

    unique_id_size = sizeof(format->unique_id);
    sprintf(contents, "id: %d major: %s age: %d introduction: %s",
        format->unique_id, format->major, format->age, format->self_introduction);

    printf("[contents]\n%s\n", contents);
    // memcpy(&contents[START_INDEX],format->unique_id, unique_id_size);

    // major_length = strlen(format->major);
    // memcpy(&contents[START_INDEX+unique_id_size], format->major, major_length);

    // age_size = sizeof(format->age);
    // memcpy(&contents[START_INDEX+unique_id_size+major_length], format->age, age_size);
 
    // self_introduction_legth = strlen(format->self_introduction);
    // memcpy(&contents[START_INDEX+unique_id_size+major_length+age_size], format->self_introduction, self_introduction_legth);
}

bool write_format_to_file(test_form *format)
{
    char write_contents[BUDDY_PAGE_SIZE] = {0};
    int created_file_descriptor =  file_open(
        "/home/eddi/proj/SDC-AI-LectureNotes/"
        "c/jaeseunglee/thirteenth/created_file/format_test.txt", 
        O_CREAT | O_RDWR | O_TRUNC, 0644);

    adjust_write_contents_from_format(write_contents, format);

    write_content_in_file(created_file_descriptor, write_contents);

    file_close(created_file_descriptor);

    return true;
}
