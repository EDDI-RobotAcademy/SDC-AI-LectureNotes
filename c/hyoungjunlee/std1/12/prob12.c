#include "prob12.h"
void prob12(void)
{
    asdf test;
    char k='k';
    
    test.a = &k;
    *(test.b)='b';
    
    printf("--> %c <--\n",*(test.a));
    printf("--> %c <--\n",*(test.b));
}
//*d2->numPtr = *((*d2).numPtr)= *(numPtr)
//d2->numPtr = (*d2).numPtr