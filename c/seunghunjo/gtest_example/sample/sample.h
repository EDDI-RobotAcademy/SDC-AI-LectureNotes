#ifndef __SAMPLE_H__
#define __SAMPLE_H__

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_USER_LENGTH         32
#define MAX_PHONE_LENGTH        32

typedef struct _for_test_struct for_test_struct;

struct _for_test_struct
{
    char *name;
    char *phone;
};

int add_all_to_end_from_start(int, int);
for_test_struct *init_for_test_struct_object(char *, char *);
char *get_for_test_struct_name(for_test_struct *);
char *get_for_test_struct_phone(for_test_struct *);
void clear_for_test_struct_object(for_test_struct *);

#ifdef __cplusplus
}
#endif

#endif