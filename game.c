#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void IntiBoard(char board[ROW][COL], int row, int  col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void Display(char board[ROW][COL], int row, int  col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
        for (j = 0; j <col; j++)
		{
			printf(" %c ", board[i][j]);
			if(j!=col-1)
			printf("|");
		}
		printf("\n");
		for (j = 0; j < col; j++)
		{
			if (i != row - 1)
			{
				printf("---");
				if (j != col - 1)
					printf("|");
			}
		}
		printf("\n");
	}
}


void player(char board[ROW][COL], int row, int  col)
{
	int x = 0;
	int y = 0;
	/*star:*/
	while (1)
	{
		printf("请玩家输入中：");
		scanf("%d%d", &x, &y);
		if (x>0&& x<=row&&y>0 && y<=col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
				printf("该点被占用!\n");
		}
		else
		{
			printf("输入错误，请重新输入！\n");
		}
	}
}

void computer(char board[ROW][COL], int row, int  col)
{
	printf("电脑输入中...\n");
	while (1)
	{
		int x = rand() % 3;
	    int y = rand() % 3;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

int panduan(char board[ROW][COL], int row, int  col)
{
	int i = 0;
	int j = 0;
	//0继续，1玩家赢，2电脑赢，3平局
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] != ' ')
		{
			if (board[i][0] == '*')//0继续，1玩家赢，2电脑赢，3平局
				return 1;
			else
				return 2;
		}
	}
	for (j = 0; j < col; j++)
	{
		if (board[0][j] == board[1][j] && board[2][j] == board[1][j] && board[2][j] != ' ')
		{
			if (board[0][j] == '*')//0继续，1玩家赢，2电脑赢，3平局
				return 1;
			else
				return 2;
		}
	}
	if (board[0][0] == board[1][1] && board[2][2] == board[1][1] && board[2][2] != ' ')
	{
		if (board[0][0] == '*')//0继续，1玩家赢，2电脑赢，3平局
			return 1;
		else
			return 2;
	}
	if (board[0][2] == board[1][1] && board[2][0] == board[1][1] && board[2][0] != ' ')
	{
		if (board[2][0] == '*')//0继续，1玩家赢，2电脑赢，3平局
			return 1;
		else
			return 2;
	}
	
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 3;
}
