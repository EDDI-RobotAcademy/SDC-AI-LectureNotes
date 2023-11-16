//1. 실수와 정수를 입력받고 그 값을 함수의 인자로 넘겨 두 수의 곱을 실수형으로 반환하여 출력하라

#include <stdio.h>

#include "quiz.h"
#include "../random/random.h"

void quiz1(const float number1, const int number2)
{
    printf("quiz1\n");
    printf("%.2f * %d = %.2f\n", number1, number2, number1 * number2);
    printf("\n");
}

//2. 두 개의 정수(num1, num2)를 입력받고 num1 << num2 값을 구하는 함수를 작성하라
//    최종적으로 결과값을 출력하도록 만드시오


void quiz2(const int num1, const int num2)
{
    printf("quiz2\n");
    int result = num1 << num2;
    printf("%d << %d 의 결과값 %d\n", num1, num2, result);
    printf("\n");
}

/*3. 실수 하나를 입력받아 소수점만 분리하고

    또 정수 부분만 분리하는 함수를 작성하시오

    (함수 총 2개를 작성하면됨)*/

void quiz3_int(const float number)    
{
    printf("quiz3_int\n");

    int int_number = (int)number;

    printf("%.2f의 정수부분 : %d\n", number, int_number);


    printf("\n");

}

void quiz3_float(const float number)
{
    printf("quiz3_float\n");
    
    float float_number = number-(int)number;

     printf("%.2f의 실수부분 : %.2f\n", number, float_number);


    printf("\n");
}    

//4. float과 double 자료형의 저장 방식에 대해서 서술하시오.

void quiz4()
{
    printf("quiz4\n");
    printf("sizeof(float): %ld, sizeof(double): %ld\n", 
                sizeof(float), sizeof(double));
    printf("\n");
}


//5. shortcut 동작 방식에 대해서 서술해보시오(&&와 ||에 대해서 각각)

void quiz5()
{
    printf("quiz5\n");
    printf("&&는 앞 뒤 둘 다 참이면 1(true)를 반환\n");
    printf("||는 앞 뒤 둘 중 하나라도 참이면 1(true)를 반환\n");
    printf("\n");
}


//6. x & ~(2의 y승 - 1)의 의미에 대해 서술하시오.
#include <math.h>
void quiz6(int x, int y)
{
    // 2의 n승 단위로 정렬하고 싶을 때 사용하는 기법
    
    printf("quiz6\n");
    printf("x & ~(2^y-1): %d", x & ~(int)(pow(2,y)-1));
    
    printf("\n");
}



//7. 함수 정의를 main 함수 아래에 적었을 경우, Compile Error가 나는 이유에 대해 기술하시오.


void quiz7()
{
    printf("quiz7\n");
    printf("사용될 함수들은 미리 선언되어있어야 하지만\n");
    printf("C언어는 기본적으로 절차지향이기에\n");
    printf("위쪽부터 컴파일을 진행해 나간다.\n");
    printf("그렇기에 main보다 아래쪽에 있는 함수는 순서상\n");
    printf("선언되지 않았다고 판단하기에 에러가 뜨는 것이다.\n");
    printf("이를 해결하려면 도메인을 분리하거나\n");
    printf("main 위쪽에서 prototype이라도 함수 선언을 해두어야 한다.\n");
    printf("\n");
}

//8. 변수의 정확한 정의에 대해 기술하시오

void quiz8()
{
    printf("quiz8\n");
    printf("변수(變數)는 변하는 값을 나타내는 문자다.\n\
        다양한 값이나 양을 넣을 수 있는 빈 자리를 나타내는 기호로\n\
        종종 주어진 집합에 있는 임의의 원소를 나타낼 때 쓴다.\n\
        변수는 수뿐만 아니라 벡터, 행렬과 함수를 나타낼 때도 쓴다.\n");
    
    printf("\n");
}

//9. Overflow와 Underflow는 어떤 경우에 나는지 기술하시오.

void quiz9()
{
    printf("quiz9\n");
    printf("Overflow는 주로 프로그램이 사용자에게 데이터(주로 문자열)을 입력받을 때 \n\
        사용자가 이미 준비된 버퍼보다 더 많은 양의 데이터를 입력할 때 발생\n\
        Stack Underflow는 스택에서 데이터를 삭제하려 할 때,\n\
        스택에 데이터가 없는 상태에서 삭제를 시도하면 발생하는 오류\n");
    
    printf("\n");
}


//10. and, or, xor, not 동작 방식에 대해 기술하고 예를 들어서 각각을 연산해보도록 하자!
#include <stdbool.h>

void quiz10()
{
    printf("quiz10\n");
    printf("비트연산자는 4가지가 있다\n\
        A & B: A B 둘 모두 1이면 1\n\
        A | B: A B 둘 중 하나 이상 1이면 1\n\
        A ^ B: A B 가 서로 다른 값이면 1\n\
        ~ A: A가 1이면 0으로, 0이면 1로 바꾼다\n");

    printf("10진수의 연산에서는 일단 2진수로 변경 후\n\
        각각의 0 1에 대해서 비교하고 연산을 진행하고\n\
        남은 결과값을 도출해낸다.\n\
        1101 & 0111 == 0101\n\
        1101 | 0111 == 1111\n\
        1101 ^ 0111 == 1010\n\
        ~연산은 값을 음수로 바꾼 뒤, -1을 추가 연산한다.\n");


        
        const int t = random_int();
       
        const int f = random_int();
        
        printf("t: %d, f: %d\n",t,f);
        printf("t & f: %d\n", t&f);
        printf("t | f: %d\n", t|f);
        printf("t ^ f: %d\n", t^f);
        printf("~f: %d\n", ~f);
    
    printf("\n");
}


//11. 10진수 33에 ~연산을 취해서 그 결과값을 알아보자!
//   (편법을 쓰지말고 2의 보수등을 취해서 구체적으로 서술하기!)


void quiz11()
{
    printf("quiz11\n");
    printf("10진수에서 ~연산은\n\
    값을 음수로 바꾼 뒤, -1을 더하면 된다.\n\
    ~33 == -33-1 이므로\n\
    -34가 나올 것이다.\n");


    printf("~33: %d\n", ~33);
    
    printf("\n");
}

//12. Memory 구조(Stack, Heap, Data, Text)에 대해서 기술하시오.





/*13. main() 함수 안에서

    인자값 2개를 가지는 doit(), letsgo() 함수를 호출

    doit() 함수는 인자값 2개를 % 연산한 결과를 반환

    letsgo() 함수는 인자값 2개를 + 연산한 결과를 반환

    doit()의 결과값과 letsgo()의 결과값을 곱한 결과를 출력하시오.*/

int doit(int num1, int num2)
{
    return num1%num2;
}

int letsgo(int num1, int num2)
{
    return num1+num2;
}

void quiz13(int num1, int num2)
{
    printf("quiz13\n");

    printf("doit * letsgo : %d\n", doit(num1,num2)*letsgo(num1,num2));

    printf("\n");
}

/*14. 2개를 숫자를 입력 받아서

    누가 더 큰지 혹은 같은지 판별할 수 있는 프로그램을 작성하시오.

    제어문을 사용하지 않고 구현하도록함!

    printf는 여러번 사용해도 무방!

    (반드시 함수를 사용하도록!)*/

void quiz14(int num1, int num2)
{
    printf("quiz14\n");
    printf("%d와 %d 중에\n",num1, num2);
    int num_sub = num1 - num2;
    int k = (num_sub >> 31) & 0x1;
    int max = num1 - k * num_sub;
    printf("더 큰 수는 %d\n",max);
    printf("\n");
}   

/*15. 3과 7.7 2개의 값을 인자로 취하는 함수를 작성하고

   2개를 더한 결과값을 반환할 때 정수형이 되게 하고

   이를 출력해서 잘 되었는지 확인하시오.*/

int quiz15(int num1, float num2)
{
    printf("quiz15\n");
    int result = num1 + num2;
    printf("3 + (int)7.7 = %d\n",result);
    printf("\n");
    return result;
    
}
