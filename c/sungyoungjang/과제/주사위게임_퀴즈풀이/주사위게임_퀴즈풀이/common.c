#include "common.h" // common 헤더를 선언하여 common.c의 함수를 호출.

bool check_even(int first_dice_number) // bool이란 자료형 논리데이터를 결과값으로 지정하고, int first_dice_number 를 매개변수로 지정후\
check_even으로 실행한다.
{
	//C에서 0은 false이며, 0이 아니면 true이다
	return (first_dice_number % 2) ? false : true; //first_dice_number가 짝수일 경우 false가 산출되고, 아닐경우 true가 도출된다.
}