#ifndef __VECTOR_H__
#define __VECTOR_H__

#include "../../account/entity/account.h"

typedef struct _vector vector;

struct _vector
{
    account *account_array;
    int x;
    int y;
    int z;
};

vector *init_vector_object(void);

#endif