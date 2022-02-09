#pragma once
#define  ROW 3
#define  COL 3
#include <stdio.h>
void IntiBoard(char board[ROW][COL], int row,int  col);
void Display(char board[ROW][COL], int row, int  col);
void player(char board[ROW][COL], int row, int  col);
void computer(char board[ROW][COL], int row, int  col);
int panduan(char board[ROW][COL], int row, int  col);