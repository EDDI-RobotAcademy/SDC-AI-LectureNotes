#include "make_format_from_file.h"

#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define BUDDY_PAGE_SIZE         4096

int file_total_length (int file_descriptor)
{
    return lseek(file_descriptor, 0, SEEK_END);
}

int find_enter_line_for_format_count(char *buffer, int total_length)
{
    int i;
    int count = 0;

    for (i = 0; i < total_length; i++)
    {
        if (!strncmp(&buffer[i], "\\n", 1))
        {
            count++;
        }
    }

    return count;
}

void set_test_form_with_read_contents(
    test_form **test_format_array, int object_count, char *read_contents)
{
    int i;
    int start, finish;
    int read_contents_length = strlen(read_contents);

    for (i = 0; i < read_contents_length; i++)
    {
        if (!strncmp(&read_contents[i], ':', 1))
        {
            start = i;
        }

        if (!strncmp(&read_contents[i], ',', 1))
        {
            finish = i;
        }

        printf("start = %d, finish = %d\n", start, finish);
    }
}

test_form **read_file_to_format(char *filename)
{
    char read_contents[BUDDY_PAGE_SIZE] = { 0 };
    int object_count;
    int total_length;

    test_form **test_format_array;

    int created_file_descriptor = file_open(
        "/home/eddi/proj/SDC-AI-LectureNotes/"
        "c/lecture/thirteenth/created_file/format_test.txt", 
            O_CREAT | O_RDWR | O_TRUNC, 0644);

    read_content_from_file(created_file_descriptor, read_contents);

    total_length = file_total_length(created_file_descriptor);
    file_close(created_file_descriptor);

    object_count = find_enter_line_for_format_count(read_contents, total_length);
    test_format_array = init_test_form_array(object_count);

    set_test_form_with_read_contents(test_format_array, object_count, read_contents);
}