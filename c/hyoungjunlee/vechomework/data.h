#ifndef __DATA_H__
#define __DATA_H__



typedef struct _vector vec;
struct _vector
{
   int x;
   int y;
   int z;
};
vec* create_vector(void);
void test(vec*vector);

#endif