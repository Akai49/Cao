#pragma once
#define ROW 3
#define	COL 3

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 声明
void InitQipan(char qipan[ROW][COL], int row, int col);
void DisplayQipan(char qipan[ROW][COL], int row, int col);
void PlayerGo(char qipan[ROW][COL], int row, int col);
void ComputerGo(char qipan[ROW][COL], int row, int col);

//输出游戏结果
//玩家赢 - ‘*’
//电脑赢 - ‘#’
//平局   - ‘Q’
//继续   - ‘R'
char IsWin(char qipan[ROW][COL], int row, int col);