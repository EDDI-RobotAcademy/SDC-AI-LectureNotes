#include "shift.h"
int shift(int num1,int num2)
{
    
    for( int i=0; i<num2; i++)
    {
        num1 *= 2;
    }
    return num1;
}