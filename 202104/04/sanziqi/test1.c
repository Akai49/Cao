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
//������ʾ��
//void DisplayBoard(char board[ROW][COL], int row, int col)
//{
//	int i = 0;
//	for (i = 0; i < row; i++)
//	{
//		//1. ��ӡһ�е�����
//		printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
//		//2. ��ӡ�ָ���
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
			//1.��ӡһ�е�����
			printf(" %c ", qipan[i][j]);
			if (j < col - 1)
				printf("|");	
		}
		printf("\n");
		//2.��ӡ�ָ���
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
	printf("����ߣ�>\n");
	while (1)
	{
		printf("������Ҫ�µ����꣺>");
		scanf("%d%d", &x, &y);
		//�ж�x��y����ĺϷ���
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (qipan[x - 1][y - 1] == ' ')
			{
				qipan[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("�����걻ռ��\n");
			}
		}
		else
		{
			printf("����Ƿ������������룡\n");
		}
	}
}

void ComputerGo(char qipan[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("������:>\n");
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
//����1����ʾ��������	
//����0����ʾ����û��

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
				return 0;//û��	
			}
		}
	}
	return 1;//���� 
}

char IsWin(char qipan[ROW][COL], int row, int col)
{
	int i = 0;
	//������
	for (i = 0; i < row; i++)
	{
		if (qipan[i][0] == qipan[i][1] && qipan[i][1] == qipan[i][2] && qipan[i][1] != ' ')
		{
			return qipan[i][1];
		}
	}
	//������
	for (i = 0; i < col; i++)
	{
		if (qipan[0][i] == qipan[1][i] && qipan[1][i] == qipan[2][i] && qipan[1][i] != ' ')
		{
			return qipan[1][i];
		}
	}
	//�����Խ���
	if (qipan[0][0] == qipan[1][1] && qipan[1][1] == qipan[2][2] && qipan[1][1] != ' ')
		return qipan[1][1];
	if (qipan[2][0] == qipan[1][1] && qipan[1][1] == qipan[0][2] && qipan[1][1] != ' ')
		return qipan[1][1];
	//�ж��Ƿ�ƽ��
	if (1 == IsFull(qipan, ROW, COL))
	{
		return 'Q';
	}
	//����
	return 'R';
}