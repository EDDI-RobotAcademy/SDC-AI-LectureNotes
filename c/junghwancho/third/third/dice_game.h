// extern의 정체는 ?
// 원어적 의미로는 외부라는 뜻을 가지고 있음
// dice_number라는 정수형 변수는 외부에 존재하는 전역 변수라는 뜻
// dice_game.c 에 있는 int dice_number = 0;를 전역적으로 쓰겠다는 뜻

extern int dice_number;

void roll_dice(void);
void print_dice_number(void);