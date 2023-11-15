#include <stdio.h>
#include "multiple.h"
#include "shift.h"
#include "seperate_int.h"
#include "seperate_other.h"
#include "13/letsgo.h"
#include "13/doit.h"
#include <math.h>
#include "14/cmp_num.h"
#include "15/returntype.h"
#define _CRT_SECURE__NO_WARNINGS
int main (void)
{
  //cmp_num();
  printf("%d",returntype(3, 7.7));
  /*정수형과 실수형을 더하고 정수형으로 출력하면 소수점 뒷자리는 절삭된다?*/
  
  

    return 0;
}
/*1. 실수와 정수를 입력받고 그 값을 함수의 인자로 넘겨 두 수의 곱을 실수형으로 반환하여 출력하라*/
  /*int a;
    float b;
    printf("입력하시오\n");
    scanf("%d",&a);
    scanf("%f",&b);
    printf("%.3f",multiple(a,b));*/
  /*
  2. 두 개의 정수(num1, num2)를 입력받고 num1 << num2 값을 구하는 함수를 작성하라
    최종적으로 결과값을 출력하도록 만드시오 */

 /* int num1,num2;
  printf("입력하시오\n");
  scanf("%d %d",&num1,&num2);
  printf("쉬프트 연산 %d\n",shift(num1,num2));*/
 
/*
3. 실수 하나를 입력받아 소수점만 분리하고
    또 정수 부분만 분리하는 함수를 작성하시오
    (함수 총 2개를 작성하면됨)*/
 /* 
  printf("입력하시오\n");
  float a;
  scanf("%f",&a);
  seperate_int(a);
  seperate_other(a);*/

  /*4. float과 double 자료형의 저장 방식에 대해서 서술하시오.*/

  /*
    float은 4바이트에 저장되고 double은 8바이트에 저장되서 double이 더 많은 데이터 범위를 표현가능하다
  */

 /*5. shortcut 동작 방식에 대해서 서술해보시오(&&와 ||에 대해서 각각)*/
  /*&& and  ||or (a && b)둘다 참이어야 참 (a || b) 둘 중에 하나만 참이어도 참*/
  
  /*6. x & ~(2의 y승 - 1)의 의미에 대해 서술하시오.*/
  /*
  &는 비트 연산자 AND x 와 y 비트 연산하면 둘다 1일 때만 1
  (2의 y승 -1)은 예를 들어 비트로 101011 이라면 ~를 붙이면 010100으로 바뀐다
  그렇게 x와 ~(2의y승-1)을 AND 연산한다는 뜻이다? 정확히 모르겠네*/
  /*
  7. 함수 정의를 main 함수 아래에 적었을 경우, Compile Error가 나는 이유에 대해 기술하시오.
   a함수가 있다고 하고 메인 함수 안에 a함수를 선언했다 위에 선언된 헤더파일이나 함수등 위부터 차례로 읽으며 내려오고 
   그렇게 메인 함수를 들어갔는데 선언된 a함수를 실행하려 했으나 a함수에 대한 정보가 없어서 컴파일 에러가 나게 된다
  */
  /*8. 변수의 정확한 정의에 대해 기술하시오*/
  /*정해지지 않은 임의의 값을 저장하는 공간? */
  /*9. Overflow와 Underflow는 어떤 경우에 나는지 기술하시오.*/
  /*오버플로우는 정해진 데이터 타입이 받을 수 있는 최댓값을 넘는 값을 넣었을 때 발생한다
    언더플로우는 정해진 데이터 타입이 받을 수 있는 최솟값보다 작을 때 발생한다
  */
  /*
  10. and, or, xor, not 동작 방식에 대해 기술하고
     예를 들어서 각각을 연산해보도록 하자!
  */
  /*
      a비트 0011 
      b비트 0101
      and 연산 둘다 1이어야 1 
           0001
      or  연산 둘 중에 하나만 1이어도 1
           0111
      xor 연산  두 비트가 다를 때 1
           0110
      not 연산  0은 1로 1은 0으로
              0101 -> 1010

  */

  /*13. main() 함수 안에서

    인자값 2개를 가지는 doit(), letsgo() 함수를 호출

    doit() 함수는 인자값 2개를 % 연산한 결과를 반환

    letsgo() 함수는 인자값 2개를 + 연산한 결과를 반환

    doit()의 결과값과 letsgo()의 결과값을 곱한 결과를 출력하시오.*/
    /*
    int a,b,i,j;
  printf("입력하시오\n");
  scanf("%d %d",&a,&b);
  i=doit(a,b);
  j=letsgo(a,b);
 
  printf("doit 반환값 ->%d letsgo 반환값 -> %d 곱한 결과 -> %d",i,j,i*j);*/