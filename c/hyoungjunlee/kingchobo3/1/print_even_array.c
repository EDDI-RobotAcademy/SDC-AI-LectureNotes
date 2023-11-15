#include "print_even_array.h"
void print_even_array(void)
{
    char arr[32];
    printf("입력하세요\n");
    scanf("%s",arr);
    int i;
    
    for(i=0;i<strlen(arr);i++)
    {
        if (i%2==0)
        {
            printf("%d번 째 글자 -->%c\n",i,arr[i]);
        }
    }
}