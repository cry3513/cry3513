#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"
void menu1()
{
	printf("*****************************\n");
	printf("***      ��������Ϸ       ***\n");
	printf("***                       ***\n");
	printf("***       �Ƿ���룿      ***\n");
	printf("***  Yes��1��    exit(0)  ***\n");
	printf("*****************************\n");
}

void game()
{
	char  board[ROW][COL] = {0};
	IntiBoard(board, ROW, COL);
	Display(board, ROW, COL);
	while (1)
	{
		int a =0;
		player(board, ROW, COL);//���
		Display(board, ROW, COL);
		a = panduan(board, ROW, COL);
		if (a == 1)
		{
			printf("���Ӯ\n");
			break;
		}
		if (a == 0)
			printf("����\n");
		else
		{
			printf("ƽ��\n");
			break;
		}
		computer(board, ROW, COL);//����
		Display(board, ROW, COL);
        a = panduan(board, ROW, COL);
		if (a == 2)
		{
			printf("����Ӯ\n");
			break;
		}
		//0������1���Ӯ��2����Ӯ��3ƽ��
		if (a == 0)
			printf("����\n");
		else
		{ 
			printf("ƽ��\n");
			break;
		}
	}
}


int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu1();
		printf("�Ƿ������Ϸ��");
		scanf ("%d", &input);
		switch(input)
		{
		case 1:
			   game();
				break; 
		case 0:
				printf("�˳�����\n");
				break;
		default:
				printf("�������,������ѡ��\n");
		}
	} while (input);
	 return 0;
}