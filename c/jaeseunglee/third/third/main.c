#include <stdio.h>
#include "print_even.h"
#include "print_even_advanced.h"
#include "print_random.h"
#include "random_generator.h"
#include "dice.h"

#include "dice_game.h"
#include "player.h"

#define LOOP_MAX 5

int main(void)
{
	const int start = 3;
	const int end = 13;
	const int random_number_count = 10;

	int loop_count = 0;
	// ���� - �� ������ ���ڿ��� ¦���� ���
	print_even_number_from_start_to_end(start, end);

	printf("���� �� ������ �ڵ�!\n\n");

	print_even_number_from_start_to_end_advanced(start, end);

	print_random_number(random_number_count);

	printf("\n\n\n");

	

	printf("�ֻ����� �����ϴ�. �������� : %d\n",roll_the_dice());

	printf("\n");

	/*dice_fight(generate_random(0, 255), generate_random(0, 255));

	printf("\n\n\n");*/



	// while ���� for���� ���������� �ݺ���
	// ���������� for�� �ణ ������ �������� ���� ���
	// while�� �ܼ��� �ݺ���ų�� �ַ� ���
	// �������� �κ��̱⿡ �ݵ�� �׷� �ʿ�� ����

	// -while�� ���� ����
	//  ���� �񱳴� if�� ����
	//  �Ұ�ȣ ���� ������ �����ϸ� �ݺ� ����
	//  ������ �������� ���ϸ� �ߴ�

	// loop_count�� LOOP_MAX(5)���� �۴ٸ� �ݺ�
	// �ٵ� ++�� �پ��ֱ� ������ loop_count�� �ݺ����� ���ڰ� 1�� �þ

	// '++' '--' ���� ���� �����ڿ� ���� ������ ������ ������
	// ���� �������� ��� '++loop_count' ����
	// �� ��쿣 ���� �� ���� ������ ���˴ϴ�.
	// ���� �������� ��� 'loop_count++'����
	// �� ��쿣 ���� �� �Ŀ� ������ ���˴ϴ�.
	while (loop_count++ < LOOP_MAX)
	{
		
		roll_dice();
	
		print_dice_number();
	}

	printf("\n");
	
	set_player_name("Hello");
	print_player_name();
	printf("\n");

	set_player1("Hello");
	set_player2("World");
	dice_fight(player1,player2);

	


	printf("\n\n\n\n\n\n\n");
	printf("asdfasdfasdf %s", set_name("aaaa"));


	return 0;

}