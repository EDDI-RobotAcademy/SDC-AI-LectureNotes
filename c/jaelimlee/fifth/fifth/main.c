#include <stdio.h>
#include "player.h"




// 주사위 굴리기
// 스킬 사용하기
// 사용자 만들기
// 승자 판정하기

int main(void)
{
	int loop;
	char* nickname[MAX_PLAYER_NUMBER] = {
		"입벌려 힐 들어간다"
		"주님 곁으로"
	};

	printf("퀴즈 풀이!\n");
	for (loop = 0; loop < MAX_PLAYER_NUMBER; loop++)
	{
		init_player_nickname(nickname[loop]);

	}
	print_player_list();

	return 0;
}