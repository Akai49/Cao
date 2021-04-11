#define  _CRT_SECURE_NO_WARNINGS 1

#include "test.h"

void InitQipan(char qipan[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			qipan[i][j] = ' ';
		}
	}
}
//不完美示范
//void DisplayBoard(char board[ROW][COL], int row, int col)
//{
//	int i = 0;
//	for (i = 0; i < row; i++)
//	{
//		//1. 打印一行的数据
//		printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
//		//2. 打印分割行
//		if (i < row - 1)
//			printf("---|---|---\n");
//	}
//}

void DisplayQipan(char qipan[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			//1.打印一行的数据
			printf(" %c ", qipan[i][j]);
			if (j < col - 1)
				printf("|");	
		}
		printf("\n");
		//2.打印分割行
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}

void PlayerGo(char qipan[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家走：>\n");
	while (1)
	{
		printf("请输入要下的坐标：>");
		scanf("%d%d", &x, &y);
		//判断x，y坐标的合法性
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (qipan[x - 1][y - 1] == ' ')
			{
				qipan[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("该坐标被占用\n");
			}
		}
		else
		{
			printf("坐标非法，请重新输入！\n");
		}
	}
}

void ComputerGo(char qipan[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑走:>\n");
	while (1)
	{

		x = rand() % row;
		y = rand() % col;
		if (qipan[x][y] == ' ')
		{
			qipan[x][y] = '#';
			break;

		}
	}

}
//返回1，表示棋盘满了	
//返回0，表示棋盘没满

int IsFull(char qipan[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (qipan[i][j] == ' ')
			{
				return 0;//没满	
			}
		}
	}
	return 1;//满了 
}

char IsWin(char qipan[ROW][COL], int row, int col)
{
	int i = 0;
	//横三行
	for (i = 0; i < row; i++)
	{
		if (qipan[i][0] == qipan[i][1] && qipan[i][1] == qipan[i][2] && qipan[i][1] != ' ')
		{
			return qipan[i][1];
		}
	}
	//竖三列
	for (i = 0; i < col; i++)
	{
		if (qipan[0][i] == qipan[1][i] && qipan[1][i] == qipan[2][i] && qipan[1][i] != ' ')
		{
			return qipan[1][i];
		}
	}
	//两条对角线
	if (qipan[0][0] == qipan[1][1] && qipan[1][1] == qipan[2][2] && qipan[1][1] != ' ')
		return qipan[1][1];
	if (qipan[2][0] == qipan[1][1] && qipan[1][1] == qipan[0][2] && qipan[1][1] != ' ')
		return qipan[1][1];
	//判断是否平局
	if (1 == IsFull(qipan, ROW, COL))
	{
		return 'Q';
	}
	//继续
	return 'R';
}