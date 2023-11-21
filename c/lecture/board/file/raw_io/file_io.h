#ifndef __FILE_IO_H__
#define __FILE_IO_H__

#ifdef __cplusplus
extern "C" {
#endif

#define _OVERRIDE(_1, _2, _3, NAME, ...) NAME

#define file_open(...) _OVERRIDE(       \
    __VA_ARGS__,                        \
    file_open3,                         \
    file_open2                          \
)(__VA_ARGS__)

int file_open(char *filename, int option, unsigned int permission);
int file_open(char *filename, int option);
void write_to_file(int file_descriptor, char *write_buffer);
void read_from_file(int file_descriptor, char *read_buffer, int size);
void reset_file_pointer(int file_descriptor);
int file_total_length(int file_descriptor);
void move_file_pointer(int file_descriptor, int point);
void file_close(int file_descriptor);

#ifdef __cplusplus
}
#endif

#endif