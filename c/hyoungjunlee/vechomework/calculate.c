#include "calculate.h"
#include "data.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
void relative_speed(vec* a_vec,vec* b_vec)
{
   vec* cal_speed_vec=(vec*)malloc(sizeof(vec));
  
   cal_speed_vec->x = b_vec->x - a_vec->x;

   cal_speed_vec->y = b_vec->y - a_vec->y;
   cal_speed_vec->z = b_vec->z - a_vec->z;
   printf("A가 B를 바라본는 상대 벡터 => (%d, %d, %d) \n",cal_speed_vec->x,cal_speed_vec->y,cal_speed_vec->z);
}
void vector_length(vec* a_vec,vec* b_vec)
{
   vec* cal_leng_vec=(vec*)malloc(sizeof(vec));
   
   cal_leng_vec->x = b_vec->x+a_vec->x;
   cal_leng_vec->y = b_vec->y+a_vec->y;
   cal_leng_vec->z = b_vec->z+a_vec->z;
   
   //printf("왜 안됨 x더한 값 %d  y더한값 %d z더한 값 %d\n",(cal_leng_vec->x),cal_leng_vec->y,cal_leng_vec->z);
   //printf("될까? 제곱 %d  제곱 %d 제곱 %d\n",(int)pow((cal_leng_vec->x),2),(int)pow((cal_leng_vec->y),2),(int)pow((cal_leng_vec->z),2));
   printf("통합 길이 => %.5f\n",(float)(sqrt(((int)pow((cal_leng_vec->x),2)+((int)pow((cal_leng_vec->y),2)+(int)pow((cal_leng_vec->z),2))))));
}