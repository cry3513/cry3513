#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"
void menu1()
{
	printf("*****************************\n");
	printf("***      三字棋游戏       ***\n");
	printf("***                       ***\n");
	printf("***       是否进入？      ***\n");
	printf("***  Yes（1）    exit(0)  ***\n");
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
		player(board, ROW, COL);//玩家
		Display(board, ROW, COL);
		a = panduan(board, ROW, COL);
		if (a == 1)
		{
			printf("玩家赢\n");
			break;
		}
		if (a == 0)
			printf("继续\n");
		else
		{
			printf("平局\n");
			break;
		}
		computer(board, ROW, COL);//电脑
		Display(board, ROW, COL);
        a = panduan(board, ROW, COL);
		if (a == 2)
		{
			printf("电脑赢\n");
			break;
		}
		//0继续，1玩家赢，2电脑赢，3平局
		if (a == 0)
			printf("继续\n");
		else
		{ 
			printf("平局\n");
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
		printf("是否进入游戏：");
		scanf ("%d", &input);
		switch(input)
		{
		case 1:
			   game();
				break; 
		case 0:
				printf("退出程序\n");
				break;
		default:
				printf("输入错误,请重新选择。\n");
		}
	} while (input);
	 return 0;
}