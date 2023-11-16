#include <stdio.h>
#include <fcntl.h>

#include "file_io/how_to_make_file.h"
#include "file_io/how_to_write_content.h"
#include "file_io/how_to_read_content.h"
// Linux OS가 메모리를 관리 할 때 Slab단위 및 Buddy단위로 관리함
// Slab은 32 * 2^n형태로 구성됨
// 그러므로 32의 배수 형태로 각을 맞추는게 좋음
// Buddy는 물리 메모리의 최소 단위인 4K (4096byte) = 2^12 을 기준으로 동작
#define SLAB_CACHE         32

int main (void)
{   

    char contents[SLAB_CACHE] = "이거 쓸래";
    char read_buffer[SLAB_CACHE];


    // 0644는 8진수임
    int created_file_descriptor =  file_open(
        "/home/eddi/proj/SDC-AI-LectureNotes/"
        "c/jaeseunglee/thirteenth/created_file/이거만들래.txt", O_CREAT | O_RDWR, 0644);

    printf("생성된 파일 디스크립터: %d\n", created_file_descriptor);

    write_content_in_file(created_file_descriptor, contents);
    reset_file_pointer(created_file_descriptor);
    read_content_from_file(created_file_descriptor, read_buffer);

    file_close(created_file_descriptor);

    return 0;
}
