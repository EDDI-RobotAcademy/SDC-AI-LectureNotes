#ifndef __SAMPLE_H__
#define __SAMPLE_H__

#ifdef __cplusplus
extern "C" {
#endif

void sample(void);

typedef struct _memory_leak_sample memory_leak_sample;


typedef memory_leak_sample *(*memory_leak_sample_constructor)(void);
typedef void (*memory_leak_sample_destructor)(memory_leak_sample* );

struct _memory_leak_sample
{
    char* message;
    char* a_device_message;
};

/*
typedef memory_leak_sample *(*memory_leak_sample_constructor)(void);

memory_leak_sample_contructor는 
memory_leak_sample*을 리턴하고
void 를 parameter로 취하는 함수 포인터 타입

typedef void (*memory_leak_sample_destructor)(memory_leak_sample* ); 

memory_leak_sample_destructor는
void를 리턴하고 
memory_leak_sample 포인터를 parameter로 취하는 함수 포인터 타입

여기서 타입이란? 변수를 작성 할 때 앞에 적는 것
int char등

그러므로 아래와 같이 memory_leak_sample_constructor constructor로 표현이 가능
*/

memory_leak_sample *init_memory_leak_sample_object();
void clear_memory_leak_sample_object(memory_leak_sample* object);
void constructor_like_memory_leak_sample(char* , char* , memory_leak_sample_constructor, memory_leak_sample_destructor);
#ifdef __cplusplus
}
#endif

#endif
