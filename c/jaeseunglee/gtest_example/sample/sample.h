#ifndef __SAMPLE_H__
#define __SAMPLE_H__

#ifdef __cplusplus
extern "C" {
#endif

void sample(void);

int add_all_start_to_end(int, int);

#define MAX_USER_LENGTH     128
#define MAX_PHONE_LENGTH    32

typedef struct _for_test_struct for_test_struct;

struct _for_test_struct
{
    char* name;
    char* phone;
};

for_test_struct *init_for_test_struct_object(char*, char*);

char* get_name(for_test_struct *);
char* get_phone(for_test_struct*);

void clear_object(for_test_struct*);


#ifdef __cplusplus
}
#endif

#endif
