#pragma once
// extern의 정체는 무엇인가?
// 원어적 의미로는 '외부'라는 뜻
// => dice_number라는 정수형 변수는 외부에 존재하는 전역변수
extern int dice_number;

void roll_dice(void);
void print_dice_number(void);