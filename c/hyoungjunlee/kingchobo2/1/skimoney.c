#include "skimoney.h"
void cal_skimoney(void)
{
    int mycost=0;
    
    int usingday=3;
    int i;

    int onedaycost =37500;
    for(i=0;i<usingday;i++)
    {
        mycost+=37500;
        
    }
    if(i>2)
    mycost *=0.8;
    printf("이용한 날짜 %d일,내가 총 내야할 돈%d원\n",usingday,mycost);
    
}