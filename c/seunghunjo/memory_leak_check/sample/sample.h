#ifndef __SAMPLE_H__
#define __SAMPLE_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _memory_leak_sample memory_leak_sample;
// memory_leak_sample * 리턴
// void 파라메터
// 함수 포인터 타입 이름 memory_leak_sample_constructor
typedef memory_leak_sample *(* memory_leak_sample_constructor)(void);
typedef void (* memory_leak_sample_destructor)(memory_leak_sample *);

struct _memory_leak_sample
{
    char *message;
    char *a_device_message;
};

memory_leak_sample *init_memory_leak_sample_object(void);
void clear_memory_leak_sample_object(memory_leak_sample *);

// void constructor_like_memory_leak_sample(
//         memory_leak_sample *(*)(void),
//         void (*)(memory_leak_sample *));
void constructor_like_memory_leak_sample(
        char *, char *,
        memory_leak_sample_constructor,
        memory_leak_sample_destructor);

#ifdef __cplusplus
}
#endif

#endif