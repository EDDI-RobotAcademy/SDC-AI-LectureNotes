#ifndef __SAMPLE_H__
#define __SAMPLE_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _memory_leak_sample memory_leak_sample;

struct _memory_leak_sample
{
    char *message;
    char *a_device_message;
};

memory_leak_sample *init_memory_leak_sample_object(void);
void clear_memory_leak_sample_object(memory_leak_sample *);

#ifdef __cplusplus
}
#endif

#endif