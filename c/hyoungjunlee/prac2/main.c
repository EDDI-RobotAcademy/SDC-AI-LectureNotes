#include <stdio.h>

int add(int a, int b){return a + b;} //덧셈함수
int sub(int a, int b){return a - b;} //뺄셈함수
int mul(int a, int b){return a * b;} //곱셈함수
int div(int a, int b){return a / b;} //나눗셈함수

int main()
{
    int (*fp[4])(int, int);  //함수 포인터 배열 선언

    fp[0] = add; // 배열[1]에 덧셈 함수의 메모리 주소 저장
    fp[1] = sub; // 배열[2]에 뺄셈 함수의 메모리 주소 저장
    fp[2] = mul; // 배열[3]에 곱셈 함수의 메모리 주소 저장
    fp[3] = div; // 배열[4]에 나눗셈 함수의 메모리 주소 저장

    for (int i = 0; i < 4; i++) {
        printf("배열[%d] 함수의 실행 값 : %d\n",i, fp[i](20, 10));
    }

    return 0;
}
