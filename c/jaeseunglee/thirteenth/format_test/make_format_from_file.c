#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>


#include "make_format_from_file.h"
#include "../file_io/how_to_make_file.h"
#include "../file_io/how_to_write_content.h"
#include "../file_io/how_to_read_content.h"

#define BUDDY_PAGE_SIZE     4096

int file_total_length(int file_descriptor)
{
    return lseek(file_descriptor,0,SEEK_END);
}

int find_enter_line_for_format_count(char *buffer, int total_length)
{
    int loop;
    int count;
    for(loop = 0; loop < total_length; loop ++)
    {
        if(!strncmp(&buffer[loop],"\\n",1))
        {
            printf("뾰옹");
            count ++;
        }
    }
    return count ;
}

void set_test_form_with_read_contents(test_form **test_form_array,int object_count,char *read_contents)
{
    int start, finish;
    int read_contents_length = strlen(read_contents)   ;
    for(int i = 0; i< read_contents_length; i++)
    {
        if(!strncmp(read_contents[i],":",1))
        {
            start = i;
        }
        if(!strncmp(read_contents[i],",",1))
        {
            finish = i;
        }
    }

    printf("start: %d, finish: %d", start, finish);
}

test_form **read_file_to_format(char *filename)
{
    char read_contents[BUDDY_PAGE_SIZE] = {0};
    int total_length;
    int object_count;
    test_form **test_form_array;

    int created_file_descriptor =  file_open(
        "/home/eddi/proj/SDC-AI-LectureNotes/"
        "c/jaeseunglee/thirteenth/created_file/format_test.txt", 
        O_CREAT | O_RDWR | O_TRUNC, 0644);

    read_content_from_file(created_file_descriptor, read_contents);
    
    total_length = file_total_length(created_file_descriptor);

    file_close(created_file_descriptor);

    object_count = find_enter_line_for_format_count(read_contents, total_length);

    test_form_array = init_test_form_array(object_count);

    set_test_form_with_read_contents(test_form_array, object_count, read_contents);
}