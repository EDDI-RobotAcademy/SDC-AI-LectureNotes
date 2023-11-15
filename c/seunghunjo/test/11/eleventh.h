#ifndef __ELEVENTH_H__
#define __ELEVENTH_H__

#define MAX_NAME_LENGTH             32


typedef struct _eleventh eleventh;

struct _eleventh
{
    char *name;
};


eleventh *init_eleven_(void);

void init_char_(eleventh *eleventh_name,char *name);

void print_eleveth_name(eleventh *eleventh_name);

#endif