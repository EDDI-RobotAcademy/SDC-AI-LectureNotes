

int main(void)
{
	//사용자 2명 
	// malloc test char 부분을 참고할 것 
	set_player_info();
	print_player_info();

	//각 사용자들은 주사위 2개씩 굴린다. 
	//첫 번째 주사위가 짝수면 두번째 주사위를 굴린다. (홀수면 첫번쨰 주사위에서 아웃.)
	//두번째 주사위는 점수에 합산, 단 숫자 2,3,4가 나오면 스킬 발동 
	// 숫자 2: 자신의 주사위 총합에 +3 
	// 숫자 3: 상대편 주사위 총합에 -4
	// 숫자 4: 그냥 죽음 

	roll_dice();
	print_dice_number();
	//malloc test integer 부분을 참고할 것 
	

	//승자 판정
	check_winner();

	return 0;
}